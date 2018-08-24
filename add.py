filename = input('Enter the filepath: ')

with open(filename) as f:
    content = f.readlines()
content = [x.strip().split(' ') for x in content]
print('No of testcases is:', content[0][0])
content.pop(0)
print('The testcases are:', content)
i = 1
for item in content:
    print('For testcase', i, ':', int(item[0]) + int(item[1]))
    # print()
    i = i + 1
