import random

def func(points):
    #main cycle
    parent = 0
    current = 0
    nachalo = -1
    k1 = 0
    k1old = 0
    ans1 = {}
    while True:
        if current == nachalo:
            break
        for i in range(0,len(points)):
            if i != current and i != parent:
                vect = {0:float(points[i][0]) - float(points[current][0]),1:float(points[i][1]) - float(points[current][1])}
                foundZnak = False
                otric = False
                ans = True
                for j in range(0,len(points)):
                    vect1 = {0:float(points[j][0]) - float(points[current][0]),1:float(points[j][1]) - float(points[current][1])}
                    ch = vect[0] * vect1[1] - vect[1] * vect1[0]
                    if ch < 0 and not foundZnak:
                        foundZnak = True
                        otric = True
                    elif not foundZnak:
                        foundZnak = True
                        otric = False
                    elif ch < 0 and not otric:
                        ans = False
                        break
                    elif ch >= 0 and otric:
                        ans = False
                        break
                if ans:
                    ans1[k1] = (points[current][0] + " " + points[current][1]).split(" ")
                    k1old = k1
                    k1 = k1 + 1
                    if nachalo == -1:
                        nachalo = current
                    parent = current
                    current = i
                    break
        if k1old == k1:
            current = current + 1
            parent = current
        k1old = k1
    return ans1

def autotest():
    points2 = {0:['0','0'],1:['1','1'],2:['1','0'],3:['0','1'],4:['0.5','0.5']}
    ans1 = func(points2)
    if ans1 == {0: ['0', '0'], 1: ['1', '0'], 2: ['1', '1'], 3: ['0', '1']}:
        return True
    return False

inptype = ""
points1 = {}

if autotest():
    print("autotest complete")
else:
    print("autotest not complete")
    exit()

#input
while inptype != "f" and inptype != "k" and inptype != "r":
    inptype = input("Input from keyboard or file or random?(k,f,r):")

if inptype == "k":
    num = int(input("Enter number of points:"))
    print("Enter coordinates of points(format:x y)")
    for i in range(0,num):
        points1[i] = input().split(" ")
elif inptype == "f":
    filename = input("Enter filename:")
    file = open(filename, "r")
    data = file.read()
    data = data.replace("\n"," ")
    data1 = data.split(" ")
    for i in range(0,int(data1[0])):
        points1[i] = (data1[2*i + 1] + " " + data1[2*i + 2]).split(" ")
elif inptype == "r":
    num = int(input("Enter number of points:"))
    for i in range(0,num):
        points1[i] = (str(random.uniform(-300,300)) + " " + str(random.uniform(-300,300))).split(" ")

ans1 = func(points1)
for s in ans1:
    print(ans1[s])