# 0x08. Palindrome integer

---

## Description :newspaper:
This project was created with learning purposes at Holberton School; on `Ubuntu 14.04` `gcc4.8.4`.

---

### Tasks :white_check_mark:

#### 0. Palindrome unsigned integer
Write a function that checks whether or not a given unsigned integer is a palindrome.
- Prototype: `int is_palindrome(unsigned long n);`
- Where `n` is the number to be checked
- Your function must return `1` if `n` is a palindrome, and `0` otherwise
- You are not allowed to allocate memory dynamically (malloc, calloc, …)
<details>
<summary>Example:</summary>

```sh
Your@Shell$ gcc -Wall -Wextra -Werror -pedantic -g3 -o palindrome 0-main.c 0-is_palindrome.c
Your@Shell$ ./palindrome 1
1 is a palindrome.
Your@Shell$ ./palindrome 11
11 is a palindrome.
Your@Shell$ ./palindrome 112
112 is not a palindrome.
Your@Shell$ ./palindrome 121
121 is a palindrome.
Your@Shell$ ./palindrome 12345678987654321
12345678987654321 is a palindrome.
Your@Shell$ ./palindrome 123456789987654321
123456789987654321 is a palindrome.
Your@Shell$ ./palindrome 1234567898654321
1234567898654321 is not a palindrome.
```
</details>

---

## Author :bust_in_silhouette:
- [Adrian Vides] | [Twitter] | [GitHub]


---

[GitHub]: <https://github.com/AdrianVides56>
[Twitter]: <https://twitter.com/termi56661>
[Adrian Vides]: <https://www.linkedin.com/in/adrianvides56/>    