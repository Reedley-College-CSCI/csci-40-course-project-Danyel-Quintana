[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/7mdzU3H2)
# CS1 Final Project - [Project Title]

## 1. Overview
- What problem does your project solve?  
While my project does not solve a problem directly it could be used as source to find a book to read or be integrated into a real world library system to keep track of book availability
- Briefly describe the purpose and key features of your program.  
This app allows you the user to browse my library of books
 You can checkout, return, sort, search, and browse all the books!
 This can be done by entering the prompted numbers
 

---

## 2. Design Decisions
- What fundamental programming constructs and data types did you use, and why?  

IP/OP for interactivity
variables to store data
conditionals for certain user IP
Loops for looping through arrays
functions for modularity
Arrays for list of an objects info
File manipulation for data storing and changing

int for number prompts
string for storing words
bool for availability
structs for grouping like data

- Why did you choose to structure your data using structs?  
because the prompt said so, and makes code easier to understand
- How did you implement searching and sorting? What algorithms did you use and why?  
because the prompt said so, allows for more interactivity
- How do you ensure data persistence between program runs?  
using functions to load and save data
- Did you consider alternative approaches? If so, why did you not use them?  
dont know other ways

---

## 3. Testing Summary
- **Structured Testing Log:** Include a table with test cases, expected output, actual output, and pass/fail status.  
- What testing methods did you use?  
1 normal/valid input test
1 invalid input test
2 sorting/searching test
1 data persistence test
- Provide examples of test inputs (valid and invalid) and describe how your program responds.  

Testcase     Descripition,            input               expected output                               output                                        P/F

TC-01:  Enter 1 to checkout book,       1                allows me to check out  "Enter the number of the book you would like to check out:"           P
                                                                a book
TC-02:  Enter 7 to cause default case,   7                      Error             "Error: Please enter an integer 1 - 6"                               P

TC-03:  Sort by Author                   1,3         Sorts and Displays by Author          Sorts and Displays by Author                                P
    
TC-04:  Search a Book              4,The_Maze_Runner    Shows The Maze Runner and Status   Shows The Maze Runner and Status                            p

TC-05: Checkout a book, exit program    1,1 exit, 5          Shows book not available          Shows book not available                                p
        check availability
---

## 4. Technical Walkthrough
- Explain the main functionality of your program.  
- **Include a link to your required video demonstration** showcasing how the project works (**3-7 minutes**). 
    Make sure it shareable without approval needed.

---

## 5. Challenges and Lessons Learned
- What challenges did you encounter while working on this project?  
I should time manage so I have to never do this again
- What key lessons did you learn about programming and problem-solving?  
That I love programming and PS but I hate rushing myself to do it
---

## 6. Future Improvements
- If you had more time, what changes or enhancements would you make?  
I would make the project more personalized by adding jokes, I would also expand the number of books