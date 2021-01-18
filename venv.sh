#!/bin/bash
if [[ "$OSTYPE" != "linux-gnu"* ]]; then
	docker run -it -v ${PWD}:/workspace ubuntu:20.04 /bin/bash
fi
#
