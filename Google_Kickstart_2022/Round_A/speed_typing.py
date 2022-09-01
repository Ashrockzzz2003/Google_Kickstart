def possible_answer(key, user_response):
    index = 0
    for letter in key:
        index = user_response.find(letter, index) + 1
        if not index:
            y = "IMPOSSIBLE"
            break
    else:
        y = len(user_response) - len(key)
    
    return y

for T in range(int(input())):
    key = str(input())
    user_response = str(input())
    print(f"Case #{T+1}: {possible_answer(key, user_response)}")
