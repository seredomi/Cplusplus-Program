# Cplusplus-Program

## Summarize the project and what problem it was solving.
This project allows a user to see an analysis of projected earnings in a savings account. They begin by entering an initial deposit amount, a monthly deposit amount, interest rate, and number of years the money has to grow. The result is a visual chart showing their earnings year by year as far as they want the program to project. Additionally, the program will show them the difference between their earning should they decide to contribute to their account monthly or not.

## What did you do particularly well?
One of my strongsuits in this project was my formatting. I liked my solution for aligning all the numbers on the rightside despite needing dollar signs on the left side. I created a function that spits out a numbers projected string width with the dollar sign and decimal trail accounted for. This allowed me to align the yearly report charts in a neat and visually pleasing way.

## Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
One thing I could have done is I could have turned the input validation into a function to reduce repition in the code and improve readability. Since the numberOfYears variable needs to be positive, not just non-negative (like the other variables), I could have made the minimum amount a parameter in the funciton, which would have made it very versatile. 

## Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
As my professor probably recalls, I initially had the code compartmentalized in 3 or 4 different files. I had multiple .cpp files and a .h file. Additionally, I had the program running as a loop where users could adjust variables and view the yearly report charts again at any point. My professor, Dr. Anthony Kutscher, pointed out how overcomplicated and unnecessary this all was, and went through a few drafts revising and simplifying the code into a single file. My professor helped me with this all along the way, and even took time to meet with me on a Zoom call to help through the process.

## What skills from this project will be particularly transferable to other projects or course work?
The I developed a lot in the user interaction aspect while working on this project. Making sure the requirements are clear, the users' input is valid, and partitioning different sections in the output to establish clear boundaries was all paramount to making this program usable. I like the simplicity of the variable data entry, which is a format I'm sure I'll bring with me to future work.

## How did you make this program maintainable, readable, and adaptable?
The entire project is essentially boiled down to 3 functions, the user's input, the yearly report charts, and the main function that implements these two. I think this simply separation makes the program very readable, and the main can easily be modified to turn it into a loop rather than a single run. And simple modifications to the two functions can ensure every implementation of the functions will be changed. The naming scheme is consistent, and comments thoroughly explain the purpose of every section of code. I think this code will be very easy to work with for any future programmer-- including myself :)
