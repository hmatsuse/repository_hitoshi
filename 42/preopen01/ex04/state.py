import sys

states = { "Oregon" : "OR", "Alabama" : "AL", "New Jersey": "NJ", "Colorado" : "CO" }
capital_cities = { "OR": "Salem", "AL": "Montgomery", "NJ": "Trenton", "CO": "Denver" }

r_states = {val : key for key, val in states.items()}
r_capital_cities = {val : key for key, val in capital_cities.items()}

def cheak(argv):
    if (len(argv) == 2):
        capital_key = r_capital_cities.get(argv[1])
        if (capital_key == None):
            print("Unknown capital city")
        else:
            print(r_states[capital_key])

cheak(sys.argv)
