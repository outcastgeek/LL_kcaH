#!/bin/bash

valgrind -v --track-origins=yes --leak-check=full --show-reachable=yes $1
