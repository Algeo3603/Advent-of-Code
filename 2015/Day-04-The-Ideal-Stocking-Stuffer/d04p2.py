import hashlib

secretKey = input()

answer = 1
while True:
    key = secretKey + str(answer)
    result = hashlib.md5(key.encode())
    result = result.hexdigest()
    if result[:6] == "000000":
        print(answer)
        break
    answer += 1
