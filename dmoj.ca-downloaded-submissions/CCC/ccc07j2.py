s = input()
txt = {'CU': 'see you', ':-)': "I'm happy", ':-(': "I'm unhappy", ';-)': 'wink', ':-p': 'stick out my tongue', '(~.~)': 'sleepy', 'TA': 'totally awesome', 'CCC': 'Canadian Computing Competition', 'CUZ': 'because', 'TY': 'thank-you', "YW": "you're welcome", 'TTYL': 'talk to you later'}
while s != "TTYL":
    if s in txt:
        print(txt[s])
    else:
        print(s)

    s = input()

print("talk to you later")