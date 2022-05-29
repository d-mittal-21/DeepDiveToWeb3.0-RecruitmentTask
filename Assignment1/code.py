import time
import hashlib
str1 = input("please enter the header string ")
encoded_str = str1.encode()
sha256str = hashlib.sha256()
sha256str.update(encoded_str)
hexstr = sha256str.hexdigest()
initial = time.time()
for i in range(2**256 - 1):
    if int(hexstr, 16) <= (0x00000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF):
        final = time.time() - initial
        print('The proof of work was done in ', final, "seconds")
        print("the target satisfying number appended to the string is ", i )
        break
    str2 = str1 + str(i)
    encoded_str = str2.encode()
    sha256str.update(encoded_str)
    hexstr = sha256str.hexdigest()
