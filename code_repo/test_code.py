from collections import defaultdict,deque
import pdb

def compute_subset_sum_from_terms():

	'''
		Check coefficients of each term in terms and
		compute a set of sets where the sum of all
		coefficients within a subset is equal to 0.
		Which implies, that their corresponding monomials
		need to evaluate to 1 for that point to be in the variety.
		And the rest of the monomials have to evaluate to 0.
	'''
	arr = [4,-5,-4]

	dp  = {}
	visit  = {}
	stack = deque()
	idx = 0
	su  = 0
	for i in range(len(arr)+1):
		dp[i] = {}
		visit[i] = {}
	def recursion_tree(idx,su,stack):
		pdb.set_trace()
		print("idx:{},sum:{}".format(idx,su))
		print("stack content:{}".format(stack))
		if idx == len(arr):
			if su == 0:
				return stack
			else:
				return None
		

		if visit[idx][su]:
			return dp[idx][su]

		visit[idx][su] = 1
		print (visit[idx])
		print (dp[idx])
		stack.push(idx)
		tmp_stack = recursion_tree(idx+1,su+arr[idx],stack)
		if tmp_stack:
			dp[idx][su].append(tmp_stack)

			
		stack.pop()
		tmp_stack = recursion_tree(idx+1,su,stack)
		if tmp_stack:
			dp[idx][su].append(tmp_stack)

		return None

compute_subset_sum_from_terms()