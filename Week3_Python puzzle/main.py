import sys


#   1.This is a messy list, the first step, please arrange it according to a law

list = ['\u000d','\u000a','\u000d','\u000a','\u8fd9','\u662f','\u4e00','\u4e2a','\u5173','\u4e8e','\u6234','\u6021','\u7684','\u5c0f','\u6e38','\u620f','\u6ca1','\u60f3','\u5230','\u771f','\u6709','\u4eba','\u65e0','\u804a','\u7684','\u67e5','\u770b','\u5168','\u90e8','\u7684','\u5185','\u5bb9']
print(list)
list.sort()
print(list)
print(len(list))

# please write your code to replace <pass>
pass


"""
My birthday is on November 11, 1998. 
I hope you can use python to calculate the day of the week.

Then find out the index numbers in the array that are num1 and num2 from the list. 
The difference between them is equal to my day of the week, 
and their sum is also equal to my birthday in a sense.
"""

num1 =int (input ('give me index_number1:'))#line:2:num1 = int(input('give me index_number1:'))
num2 =int (input ('give me index_number2:'))#line:3:num2 = int(input('give me index_number2:'))
def myfunc ():#line:5:def myfunc():
    if abs (int (num2 )-int (num1 ))==3 :#line:6:if abs(int(num2)-int(num1)) == 3:
        if num1 ==14 and num2 ==17 :#line:7:if  num1 == 14 and num2 == 17:
            print ("You are right! ")#line:8:print("You are right! ")
        elif num1 ==17 and num2 ==14 :#line:9:elif num1 == 17 and num2 ==14:
            print ("Congratulations! You are right! ")#line:10:print("Congratulations! You are right! ")
        else :#line:12:else:
            O0OO0OO0OO00O0O0O =int (num1 %100 /10 )#line:13:a1 = int(num1 % 100 / 10)
            O000OOOO00O000OOO =num1 %10 #line:14:a2 = num1 % 10
            O000000000OO0OOO0 =int (num2 %100 /10 )#line:15:b1 = int(num2 % 100 / 10)
            O000000OO0OOOO0O0 =num2 %10 #line:16:b2 = num2 % 10
            O0O00O00O0O0O0O00 =int (O000OOOO00O000OOO +O000000OO0OOOO0O0 )#line:18:c1 = int(a2 + b2)
            print (O0OO0OO0OO00O0O0O ,O000000000OO0OOO0 ,O0O00O00O0O0O0O00 ,"is not my birthday")#line:19:print(a1,b1,c1, "is not my birthday")
    else :#line:20:else:
        print ("Oh~no, think again~")#line:21:print("Oh~no, think again~")
        sys .exit ()#line:22:sys.exit()
myfunc ()#line:25:myfunc()
x =list [num1 ]#line:27:x = list[num1]
y =list [num2 ]#line:28:y = list[num2]
print ("My name is {}{}".format (x ,y ))#line:29:print("My name is {}{}".format(x,y))
print ("{}{} is Yi Dai's Chinese name? hhh".format (x ,y ))