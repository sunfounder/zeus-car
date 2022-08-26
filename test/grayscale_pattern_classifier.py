# usage:
# run: python3 grayscale_pattern_classifier.py
# Will loop all possibilities and ask for input.
# run: python3 grayscale_pattern_classifier.py [name]
# Will loop for only the selected patterns.
#
# After everything done, copy thecont byte etc to the arduino code.
# And dont foget to replace the output angle_list and offset list of this file.
#
# Normaly angle 45 and -45,  0 and 90, offset -1 and 1 will have same numbers of patterns.
# If yours don't mind to check every pattern types again carefully, with `python3 grayscale_pattern_classifier.py [pattern name]`
# like: python3 grayscale_pattern_classifier.py ANGLE_N45

def usage():
    print("Usage: python3 grayscale_pattern_classifier.py [name]")
    quit()

import enum
from numpy import angle
import sys

def draw_pattern(str):
    str = str.replace("0b", "")
    # add 0
    while len(str) < 8:
        str = "0" + str
    str = str.replace("0", "○")
    str = str.replace("1", "●")
    li = list(str)
    li.reverse()
    result =  "    {7} →  {0}\n"
    result += "  ↗        ↘\n"
    result += "{6}            {1}\n"
    result += "↑            ↓\n"
    result += "{5}            {2}\n"
    result += "  ↖        ↙\n"
    result += "    {4}  ← {3}\n"
    result = result.format( *li )
    print(result)

angle_names = ["ANGLE_N45", "ANGLE_0", "ANGLE_45", "ANGLE_90", "ANGLE_IGNORE"]
offset_names = ["OFFSET_N1", "OFFSET_0", "OFFSET_1", "OFFSET_IGNORE"]

angle_list = [[1, 2, 3, 5, 7, 16, 32, 40, 48, 56, 68, 72, 76, 80, 88, 104, 108, 112, 120, 130, 131, 132, 133, 134, 135, 136, 140, 141, 196, 198, 200, 204, 216], [6, 9, 11, 13, 15, 25, 96, 137, 144, 145, 152, 153, 176, 208, 240], [4, 8, 10, 12, 14, 17, 18, 19, 20, 22, 26, 27, 28, 30, 33, 34, 35, 49, 50, 51, 54, 64, 65, 97, 99, 128, 160, 161, 177, 192, 193, 224, 225], [24, 36, 38, 44, 52, 60, 66, 67, 70, 98, 100, 102, 129, 194, 195], [0, 21, 23, 29, 31, 37, 39, 41, 42, 43, 45, 46, 47, 55, 57, 58, 59, 61, 62, 63, 69, 71, 73, 74, 75, 77, 78, 79, 82, 83, 84, 85, 86, 87, 89, 90, 91, 92, 93, 94, 95, 101, 103, 105, 106, 107, 109, 110, 111, 113, 114, 115, 116, 117, 118, 119, 121, 122, 123, 124, 125, 126, 127, 138, 139, 142, 143, 146, 147, 148, 149, 150, 151, 154, 155, 156, 157, 158, 159, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 197, 199, 201, 202, 203, 205, 206, 207, 209, 210, 211, 212, 213, 214, 215, 217, 218, 219, 220, 221, 222, 223, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 53, 81]]

offset_list = [[16, 32, 33, 40, 48, 56, 64, 65, 72, 80, 88, 96, 97, 99, 104, 108, 112, 120, 128, 144, 160, 161, 176, 177, 192, 193, 208, 216, 224, 225, 240, 66, 67, 129, 194, 195], [17, 25, 34, 38, 49, 50, 51, 68, 70, 76, 98, 100, 102, 136, 137, 140, 145, 152, 153, 200, 204, 19, 196, 35], [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 18, 20, 22, 26, 27, 28, 30, 54, 130, 131, 132, 133, 134, 135, 141, 198, 24, 44, 52, 60, 36], [0, 21, 23, 29, 31, 37, 39, 41, 42, 43, 45, 46, 47, 55, 57, 58, 59, 61, 62, 63, 69, 71, 73, 74, 75, 77, 78, 79, 81, 82, 83, 84, 85, 86, 87, 89, 90, 91, 92, 93, 94, 95, 101, 103, 105, 106, 107, 109, 110, 111, 113, 114, 115, 116, 117, 118, 119, 121, 122, 123, 124, 125, 126, 127, 138, 139, 142, 143, 146, 147, 148, 149, 150, 151, 154, 155, 156, 157, 158, 159, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 197, 199, 201, 202, 203, 205, 206, 207, 209, 210, 211, 212, 213, 214, 215, 217, 218, 219, 220, 221, 222, 223, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 53]]

def verify(value, type="Both"):
    str = bin(value)
    draw_pattern(str)
    if type == "Both" or type == "Angle":
        for i, angles in enumerate(angle_list):
            if value in angles:
                print("Angle:", angle_names[i])
                print("  1: -45\n  2: 0\n  3: 45\n  4: 90\n  5: Ignore")
                break
        new = input()
        if new != "":
            index = angle_list[i].index(value)
            angle_list[i].pop(index)
            angle_list[int(new)-1].append(value)
    if type == "Both" or type == "Offset":
        for i, offset in enumerate(offset_list):
            if value in offset:
                print("Offset:", offset_names[i])
                print("  1: -1\n  2: 0\n  3: 1\n  4: Ignore")
                break
        new = input()
        if new != "":
            index = offset_list[i].index(value)
            offset_list[i].pop(index)
            offset_list[int(new)-1].append(value)

def test_result():
    print("angle_list = %s\n" % angle_list)
    print("offset_list = %s\n" % offset_list)

def final_result():
    for i, name in enumerate(angle_names):
        print("const byte %s_SIZE = %s;" % (name, len(angle_list[i])))
        print("const byte %s_LIST[] = {\n" % angle_names[i], end="")
        for j, value in enumerate(angle_list[i]):
            if j % 8 == 0:
                print("  ", end="")
            print("0b{:08b}, ".format(value), end="")
            if j % 8 == 7:
                print("")
        print("};")
    for i, name in enumerate(offset_names):
        print("const byte %s_SIZE = %s;" % (name, len(offset_list[i])))
        print("const byte %s_LIST[] = {\n" % offset_names[i], end="")
        for j, value in enumerate(offset_list[i]):
            if j % 8 == 0:
                print("  ", end="")
            print("0b{:08b}, ".format(value), end="")
            if j % 8 == 7:
                print("")
        print("};")

try:
    type = "Both"
    patternList = None
    pattern = None
    if len(sys.argv) > 1:
        if sys.argv[1] in angle_names:
            patternList = angle_list[angle_names.index(sys.argv[1])]
            type = "Angle"
        elif sys.argv[1] in offset_names:
            patternList = offset_list[offset_names.index(sys.argv[1])]
            type = "Offset"
        else:
            try:
                patternList = [int(sys.argv[1], 2)]
            except ValueError:
                usage()
    else:
        patternList = range(256)
    for i, value in enumerate(patternList):
        print("[%s%s]" % ("="*int(i/len(patternList)*80), " "*int(80-i/len(patternList)*80)))
        verify(value, type)
finally:
    test_result()
    final_result()