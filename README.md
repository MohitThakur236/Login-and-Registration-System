# Login and Registration System:-

A console-based Login and Registration System developed in C++ using file handling. The program allows users to register new accounts, validate usernames and passwords, and log in using stored credentials.

## Features:-

- User registration
- User login authentication
- Duplicate username detection
- Username validation
- Password strength validation
- Limited login attempts
- File-based credential storage
- Persistent user data using data.txt
- Menu-driven interface

## Password Requirements:-

The password must:

- Be at least 6 characters long
- Contain at least one alphabet
- Contain at least one digit
- Contain at least one special character

## Username Requirements

- Must be longer than 3 characters
- Must not contain spaces
- Must be unique

## How It Works

During registration, the program checks whether the username already exists and validates the username and password. Valid credentials are then stored in the data.txt file.

During login, the program reads the stored credentials from data.txt and compares them with the username and password entered by the user. Users are allowed a limited number of attempts if they enter an incorrect password.

## File Structure

Login-and-Registration-System/
│
├── Login_registration.cpp
├── data.txt
├── .gitignore
└── README.md


## Concepts Used:-

- C++
- Functions
- File Handling
- ifstream and ofstream
- Loops
- Conditional Statements
- String Handling
- Input Validation
- Basic Authentication Logic

## Note:-

This project is designed for learning purposes. User credentials are currently stored in plain text in data.txt. In a real-world application, passwords should be hashed and stored securely.
