def func(pryam):
    lines = []
    for i in range(0,len(pryam)):
        if(pryam[i][2] < pryam[i][0]):
            pryam[i][0],pryam[i][2] = pryam[i][2],pryam[i][0]
            pryam[i][1],pryam[i][3] = pryam[i][3],pryam[i][1]

    pryam.sort(key=lambda a : a[0])
    lines.append([0,((pryam[0][2] - pryam[0][0])**2 + (pryam[0][3] - pryam[0][1])**2)**(1/2)])
    for i in range(1, len(pryam)):
        x = ((pryam[i][0] - pryam[0][0])**2 + (pryam[i][1] - pryam[0][1])**2)**(1/2)
        r = ((pryam[i][2] - pryam[i][0])**2 + (pryam[i][3] - pryam[i][1])**2)**(1/2)
        lines.append([x,r])
    ans = [0,lines[0][1]]
    ans1 = [0]
    maxt = [0,lines[0][1]]
    maxt1 = [0]
    for i in range(1,len(lines)):
        if lines[i][0] - ans[0] <= ans[1]:
            ans[1] = ans[1] + lines[i][1]
            ans1.append(i)
        else:
            if maxt[1] < ans[1]:
                maxt[0] = ans[0]
                maxt[1] = ans[1]
                maxt1.clear()
                for j in ans1:
                    maxt1.append(j)
            ans1.clear()
            ans1.append(i)
            ans[0] = lines[i][0]
            ans[1] = lines[i][1]
    if maxt[1] < ans[1]:
        maxt[0] = ans[0]
        maxt[1] = ans[1]
        maxt1.clear()
        for i in ans1:
            maxt1.append(i)
    return maxt1

def autotest():
    pryam = [[1,2,3,4],[3,4,7,8],[9,10,11,12],[11,12,16,17]]
    a = func(pryam)
    if(a == [2,3]):
        return True
    return False

if autotest():
    print("autotest complete")
else:
    print("autotest not complete")
    exit()

inptype = ""
pryam = []

#input
while inptype != "f" and inptype != "k":
    inptype = input("Input from keyboard or file or random?(k,f):")

if inptype == "k":
    num = int(input("Enter number of points:"))
    print("Enter coordinates of points(format:x1 y1 x2 y2)")
    for i in range(0,num):
        temp = input().split(" ")
        temp[0] = float(temp[0])
        temp[1] = float(temp[1])
        temp[2] = float(temp[2])
        temp[3] = float(temp[3])
        pryam.append(temp)
elif inptype == "f":
    filename = input("Enter filename:")
    file = open(filename, "r")
    data = file.read()
    data = data.replace("\n"," ")
    data1 = data.split(" ")
    for i in range(0,int(data1[0])):
        temp = (data1[4*i + 1] + " " + data1[4*i + 2] + " " + data1[4*i + 3] + " " + data1[4*i + 4]).split(" ")
        temp[0] = float(temp[0])
        temp[1] = float(temp[1])
        temp[2] = float(temp[2])
        temp[3] = float(temp[3])
        pryam.append(temp)


maxt1 = func(pryam)
for i in maxt1:
    print(pryam[i])