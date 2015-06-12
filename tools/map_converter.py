import sys
import csv

def main():
    print "hello"
    with open("tools/map_sheet.csv", "rb") as fin:
        with open("tools/map_output.dat", "wb") as fout:
            content = csv.reader(fin, dialect="excel", delimiter=",")

            x = 0
            y = 0

            for i, row in enumerate(content):
                x = 0
                if i > 0:
                    for j, item in enumerate(row):
                        if j > 0:
                            if len(item) != 0 and item != "" and item != 0:
                                itemInt = int(item, 16)
                                ss = ""
                                ss = hex(itemInt) + ", " + hex(x) + ", " + hex(y)
                                print ss
                                buff = ""
                                buff = chr(itemInt) + chr(x) + chr(y)
                                fout.write(buff)
                            x += 8
                    y += 8

            fout.close()
            fin.close()

if __name__ == "__main__":
    main()