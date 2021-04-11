string = "g fmnc wms bgblr rpylqjyrc gr zw fylb. rfyrq ufyr amknsrcpq ypc dmp. bmgle gr gl zw fylb gq glcddgagclr ylb rfyr'q ufw rfgq rcvr gq qm jmle. sqgle qrpgle.kyicrpylq() gq pcamkkclbcb. lmu ynnjw ml rfc spj."


# string = "map"

def func_one(string):
    new_string = ""
    for letter in string:
        if letter == "y":
            new_string += "a"
        elif letter == "z":
            new_string += "b"
        elif ord(letter) >= 97 and ord(letter) <= 120:
            new_string += chr(ord(letter) + 2)
        else:
            new_string += letter
    return new_string


def func_two(string):
    rule = str.maketrans("abcdefghijklmnopqrstuvwxyz", "cdefghijklmnopqrstuvwxyzab")
    return string.translate(rule)


print(func_two(string))
print(func_one(string))
print(func_two("map"))
