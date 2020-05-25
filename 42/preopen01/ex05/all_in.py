import sys

states = { "Oregon" : "OR", "Alabama" : "AL", "New Jersey": "NJ", "Colorado" : "CO" }
capital_cities = { "OR": "Salem", "AL": "Montgomery", "NJ": "Trenton", "CO": "Denver" }

r_states = {val : key for key, val in states.items()}
r_capital_cities = {val : key for key, val in capital_cities.items()}

def cheak(argv):
    state_key = states.get(argv)
    capital_key = r_capital_cities.get(argv)
    if (state_key == None and capital_key == None):
        print(argv ,"is neither a capital city nor a state")
    elif (state_key != None):
        print(capital_cities[state_key] ,"is the capital of" ,r_states[state_key])
    elif (capital_key != None):
        print(capital_cities[capital_key],"is the capital of" ,r_states[capital_key])
 
argv = []
for l in sys.argv[1].split(','):
    if l != ' ':
        argv.append(l)

i = 0
while (i < len(argv)):
    cheak(argv[i].strip(' ').title())
    i += 1
