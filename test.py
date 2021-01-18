#!/usr/bin/python3
import time
from timeloop import Timeloop
from datetime import timedelta
from argparse import ArgumentParser

tl = Timeloop()
filename = 'test'
sample_rate = 1000
file = open(filename, 'a')
@tl.job(interval=timedelta(milliseconds=sample_rate))
def sample_robot_state():
    # read state here
    file.write(time.ctime() + '\n')
    
def step():
    pass
if __name__ == "__main__":
    arg_parser = ArgumentParser('franka_data_collector')
    arg_parser.add_argument('-d', '--output-dir', help='set output directory name')
    arg_parser.add_argument('-o', '--output', help='set output filename') # "-o", "--optional-arg", help="optional argument", dest="opt", default="default"
    arg_parser.add_argument('-s', '--step', help='sample by step', action='store_true')#, dest='step', type=bool, )
    arg_parser.add_argument('-r', '--rate', help='sample/ms', dest='rate', type=int)
    arg = arg_parser.parse_args()
    if arg.step:
        while True:
            try:
                step()
            except KeyboardInterrupt:
                pass
    if arg.rate:
        sample_rate = arg.rate
        tl.start(block=True)
    file.close()
