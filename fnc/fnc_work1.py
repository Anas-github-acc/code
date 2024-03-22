text = """PFC
REC
IRFC
MACROTECH DEVLOPERS
POLYCAB INDIA LTD
SHRIRAM FINANCE
JIO FINANCE
UNION BANK
IOB

UPL
PI INDUSTRIES
IRCTC
BOSCH
SAMVARDHANA MOTHERSON
HERO MOTOCORP
ADANI WILMAR

Mazagon Dock
SUZLON
SJVN
KEI INDUSTRIES
EXIDE INDUSTRIES

BATA
PFIZER
BHARAT DYNAMICS
Whirlpool
Laurus Labs

HONASA CONSUMERS
DOMS
CELLO WORLD
MUTHOOT MICRO
GANDHAR OIL
"""
text = text.split('\n')

import pandas as pa
df = pa.read_excel('MCAP31122023.xlsx', sheet_name='Sheet1')
dict = {}
sym = list(df['Symbol'])
cmp = list(df['Company Name'])
for i in range(len(cmp)):
    try:
        cmp[i] = cmp[i].lower()
    except:
        pass
def cmptest(txt):
    for i in range(len(cmp)):
        if(cmp[i].find(txt.lower()) != -1):
            # print("--> ",txt , " | " , cmp[i])
            return cmp[i]
    return False

cap = df['Market capitalization as on December 31, 2023\n(In Lakhs)']
for txt in text:
    try:
        if(txt == ''):
            dict[''] = ''
        elif(txt in sym):
            dict[txt] = round(cap[sym.index(txt)])
        elif cmptest(txt):
            dict[txt] = round(cap[cmp.index(cmptest(txt))])
        else:
            dict[txt] = ''
    except:
        pass
print(dict)
to_excel = pa.DataFrame(dict.items(), columns=['Company Name', 'Market capitalization as on December 31, 2023\n(In Lakhs)'])
to_excel.to_excel('new.xlsx', sheet_name='Sheet2', index=False)