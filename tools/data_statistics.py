#!/usr/bin/python3

'''
数据统计与分析脚本，主要是提取，统计，分析 测试中打印到文本中的数据信息
'''

import sys

#def action(file):
    

def check_out_line(file_in, file_out):
    with open(file_in, "r") as fin:
        with open(file_out, "w") as fout:
            last = 0
            for line in fin:
                #index = line.find("ts:")
                index = line.find("T01")
                index1 = line.find("frame")
                if index >= 0:
                    fout.write(line[index:-4] + "\n")
                
                if index1 >= 0:
                    #fout.write(line[index1:-4] + "\n")
                    tmp = int(line[index1 + 10:-4])
                    diff = tmp - int(last)
                    last = tmp
                    fout.write(str(diff) + "\n")

   
if __name__ == "__main__":
    check_out_line(sys.argv[1], sys.argv[2])