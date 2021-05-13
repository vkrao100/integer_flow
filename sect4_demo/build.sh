#!/bin/bash

echo "run build_demo.sh"
echo ""
echo ""
echo "build demo_polylib"
(cd demo_polylib ; ./configure.sh && make)
echo ""
echo "build demo_polysolver"
echo ""
(cd demo_polysolver ; ./configure.sh && make )
echo ""
echo ""
echo "done build_demo.sh"
