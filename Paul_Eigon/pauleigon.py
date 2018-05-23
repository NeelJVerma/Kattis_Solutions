serves, paul, opponent = map(int, input().split())

print('paul' if ((paul + opponent) // serves) & 1 == 0 else 'opponent')