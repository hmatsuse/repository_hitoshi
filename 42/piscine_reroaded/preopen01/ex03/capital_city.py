import sys

states = { "Oregon" : "OR", "Alabama" : "AL", "New Jersey": "NJ", "Colorado" : "CO" }
capital_cities = { "OR": "Salem", "AL": "Montgomery", "NJ": "Trenton", "CO": "Denver" }

def cheak(argv):
    if (len(argv) == 2):
        state_key = states.get(argv[1])
        if (state_key == None):
            print("Unknown state")
        else:
            print(capital_cities[state_key])

cheak(sys.argv)
