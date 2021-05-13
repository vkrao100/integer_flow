#!/usr/bin/python
# script to generate alg files based on inputs
#Author: Vikas Rao

import os
import sys
import subprocess

def main():

    # collect the verilog benchmark to work on
    global stageRef
    multSize    = sys.argv [-1]
    baseName    = os.path.join("multiplier" + multSize + "X" + multSize)
    fileName    = os.path.join(baseName + ".alg")
    oFile       = open(fileName,'w') 
    stageStart  = 0
    
    initial_variable_structure(multSize, oFile)
    
    for stageIndex in range(stageStart, (int(multSize)+1)):
        recursive_stage_ppa_creator(stageIndex, multSize, oFile)
        
#    directory_structure(baseName, fileName)

def initial_variable_structure(multSize, oFile):
    
    opVariableList  = variableNames_generator("Z", int(multSize)*2)
    imdVariableList = imdvariableNames_generator(int(multSize))
    ip1VariableList = variableNames_generator("a", int(multSize))
    ip2VariableList = variableNames_generator("b", int(multSize))
    
    globVariableList = opVariableList + imdVariableList + ip1VariableList + ip2VariableList
    
    #variable list line
    for content in globVariableList:
        oFile.write(content+',')
    
    #irrelevant fillers until line 5 as Utkarsh's script processes only from line 6
    oFile.write(';\n'+';\n'+'Z;\n'+'X^2+X+1;\n'+'s3;\n')

def recursive_stage_ppa_creator(stageIndex, multSize, oFile):

    rangeStart = 0
    if stageIndex != int(multSize):
        for aIndex in range(rangeStart,int(multSize)):
            recursiveStageMultipliers = os.path.join("s"+str(stageIndex)+"_"+str(aIndex)+" + "+"a"+str(aIndex)+"*b"+str(stageIndex)+";")
            oFile.write(recursiveStageMultipliers+'\n')
    
    #a0.b0 and is our first product bit output
    if stageIndex == 0:
        firstProdOut = os.path.join("Z0 + sp0_0;\n")
        oFile.write(firstProdOut)
        for aIndex in range(rangeStart,int(multSize)):
            recursivePpaStageVars = os.path.join("sp"+str(stageIndex)+"_"+str(aIndex)+" + "+"s"+str(stageIndex)+"_"+str(aIndex)+";")
            oFile.write(recursivePpaStageVars+'\n')
    #first carry in value is always zero at stage 1
    elif stageIndex == 1:
        firstSpInit  = os.path.join("sp0"+"_"+str(multSize)+";")
        oFile.write(firstSpInit+'\n')
    else:
        #create p*stage*X*n values from first pair of and xor's within ppa
        for fiIndex in range(rangeStart,int(multSize)):
            fiPpaPropOutput = os.path.join("P"+str(stageIndex-1)+"X"+str(fiIndex)+" + "+"sp"+str(stageIndex-2)+"_"+str(fiIndex+1)+"+"+"s"+str(stageIndex-1)+"_"+str(fiIndex)+";")
            fiPpaGnrtOutput = os.path.join("P"+str(stageIndex-1)+"D"+str(fiIndex)+" + "+"sp"+str(stageIndex-2)+"_"+str(fiIndex+1)+"*"+"s"+str(stageIndex-1)+"_"+str(fiIndex)+";")
            oFile.write(fiPpaPropOutput+'\n'+fiPpaGnrtOutput+'\n')
            
        #call recursion and create a carry forward logic to feed the next product and sum outputs
        for carryIndex in range(rangeStart,int(multSize)):
            carry_recursion_creator(carryIndex, stageIndex, oFile)
        
        #if not last stage, call recursion to assign the 0th bit xor gate at every ppa stage to the product output
        if stageIndex != (int(multSize)):
            lowerPropAssign1 = os.path.join("sp"+str(stageIndex-1)+"_0"+" + "+"P"+str(stageIndex-1)+"X0"+";")
            lowerPropAssign2 = os.path.join("Z"+str(stageIndex-1)+" + "+"sp"+str(stageIndex-1)+"_0"+";")
            oFile.write(lowerPropAssign1+'\n')
            oFile.write(lowerPropAssign2+'\n')
        
        #create product outputs using xor within ppa stages using current xor sum xor'd with previous carry
        for productIndex in range(rangeStart+1,int(multSize)):
            productAssign = os.path.join("sp"+str(stageIndex-1)+"_"+str(productIndex)+" + "+"P"+str(stageIndex-1)+"X"+str(productIndex)+"+"+"P"+str(stageIndex-1)+"C"+str(productIndex-1)+";")
            oFile.write(productAssign+'\n')
            #assign the calculated carry into next propgate input 
            if productIndex == int(multSize)-1:
                lastCarryAssign = os.path.join("sp"+str(stageIndex-1)+"_"+str(productIndex+1)+" + "+"P"+str(stageIndex-1)+"C"+str(productIndex)+";")
                oFile.write(lastCarryAssign+'\n')
        
        
    #if last stage, then assign all sp* outputs to final stage of Z outputs
    if stageIndex == (int(multSize)):
        #sp to PX assignment 
        finalpx0Assign = os.path.join("sp"+str(stageIndex-1)+"_0"+" + "+"P"+str(stageIndex-1)+"X0"+";")
        oFile.write(finalpx0Assign+'\n')
        zIndex = stageIndex-1
        for opIndex in range(rangeStart,int(multSize)+1):
            finalOutputAssign = os.path.join("Z"+str(zIndex)+" + "+"sp"+str(stageIndex-1)+"_"+str(opIndex)+";")
            oFile.write(finalOutputAssign+'\n')
            zIndex += 1
            
def carry_recursion_creator(carryIndex, stageIndex, oFile):
    
    if carryIndex == 0:
        carryLogic = os.path.join("P"+str(stageIndex-1)+"C"+str(carryIndex)+" + "+"P"+str(stageIndex-1)+"D"+str(carryIndex)+";"+"\n")
        oFile.write(carryLogic)
    else:
        carryLogic = os.path.join("P"+str(stageIndex-1)+"C"+str(carryIndex)+" + "+"P"+str(stageIndex-1)+"D"+str(carryIndex)+"*"+"P"+str(stageIndex-1)+"X"+str(carryIndex)+"*"+"P"+str(stageIndex-1)+"C"+str(carryIndex-1)+" + "+"P"+str(stageIndex-1)+"D"+str(carryIndex)+" + "+"P"+str(stageIndex-1)+"X"+str(carryIndex)+"*"+"P"+str(stageIndex-1)+"C"+str(carryIndex-1)+";"+"\n")
        oFile.write(carryLogic)
    
        
def imdvariableNames_generator(multSize):
    
    #ppa stage carry input creator
    recursiveImdVariableList = []
    stageStart = 0
    
    for stageIndex in range(int(multSize), stageStart, -1):
        if stageIndex >= 2:
            # for multIndex in range(stageStart, int(multSize+1)):
            for multIndex in range(int(multSize), stageStart-1, -1):
                finalAssignVar = os.path.join("sp"+str(stageIndex-1)+"_"+str(multIndex))
                recursiveImdVariableList.append(finalAssignVar)
            for carryIndex in range(int(multSize)-1, stageStart-1, -1):
                carryVar = os.path.join("P"+str(stageIndex-1)+"C"+str(carryIndex))
                recursiveImdVariableList.append(carryVar)
            for carryIndex in range(int(multSize)-1, stageStart-1, -1):
                propVar  = os.path.join("P"+str(stageIndex-1)+"X"+str(carryIndex))
                recursiveImdVariableList.append(propVar)
                genVar  = os.path.join("P"+str(stageIndex-1)+"D"+str(carryIndex))
                recursiveImdVariableList.append(genVar)
            for carryIndex in range(int(multSize)-1, stageStart-1, -1):
                sumip2Index = os.path.join("s"+str(stageIndex-1)+"_"+str(carryIndex))
                recursiveImdVariableList.append(sumip2Index)
        elif stageIndex == 1:
            for stage0Index2 in range(int(multSize), stageStart-1, -1):
                firstStageOp2 = os.path.join("sp"+str(stageIndex-1)+"_"+str(stage0Index2))
                recursiveImdVariableList.append(firstStageOp2)
            for stage0Index1 in range(int(multSize)-1, stageStart-1, -1): 
                firstStageOp1 = os.path.join("s"+str(stageIndex-1)+"_"+str(stage0Index1))
                recursiveImdVariableList.append(firstStageOp1)
                
    return recursiveImdVariableList
        
def directory_structure(baseName, fileName):

    FNULL = open(os.devnull, 'w')
    cmd = 'mkdir -p ' + baseName
    subprocess.call(cmd,shell=True,stdout=FNULL)
    cmd = 'mv ' + fileName + " " + baseName
    subprocess.call(cmd,shell=True,stdout=FNULL)

def variableNames_generator(variableType, numberOfVariables):
    
    variableList = []
    rangeStart   = 0

    for index in range(rangeStart,int(numberOfVariables)):
        newVar = os.path.join(variableType + str(index))
        variableList.append(newVar)
    
    return variableList

if __name__ == "__main__":
    main()