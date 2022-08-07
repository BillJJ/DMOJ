data =[]

nums_data = int(input())

for i in range(nums_data):
  inp = input()
  
  if inp[1] == " ":
    splitted = [inp[0], inp[2:]]
  else:
    splitted = [inp[:2], inp[3: ]]

  remove = int(splitted[0])
  word = splitted[1]

  splitted[1] = word[ : remove - 1] + word[remove: ]
  
  data.append(splitted[1])

for i in range(len(data)):
  print(str(i + 1), data[i])