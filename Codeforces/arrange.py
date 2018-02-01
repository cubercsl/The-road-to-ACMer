#coding utf-8

import os
import sys
import re

def main():
    ls = os.popen("ls").read().split('\n')[:-1]
    for item in ls:
        if not '.cpp' in item:
            continue
        match = re.findall(r'[0-9]+', item)
        for folder in match:
            if not os.path.exists('./%s'% folder):
                os.popen("mkdir %s"% folder)
        os.popen("mv %s %s"% (item, folder))

if __name__ == '__main__':
    main()
