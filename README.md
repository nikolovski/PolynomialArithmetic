<h1> PolynomialArithmetic </h1>
<p>Write a program to input pairs of polynomials and output:</p>
<ul>Output them in canonical form. Then compute and output:
1. Their sum (add them)
2. Their difference (subtract them)
3. Their product (multiply them).
</ul>
Question: What do we mean by “canonical form”?
Answer: This is a representation where
(a) The polynomial is written from the highest powers to the lowest, and
(b) All terms with the same power are “consolidated.” If the consolidation leads to a zero
coefficient, do not display that term.
Example: If the input were
-1+5x+20x^3-9x^2-2x+x^2-2x^3+x^9,
You would change it to:
x^9+18x^3-8x^2+3x-1
The input:
Read the input from a file called input.txt in the same directory as your program.
Each line (terminated by a newline character) in the file will represent a polynomial. The
line will contain a list of integers, which when taken in pairs, will represents the
coefficient and exponent of each of the terms in the polynomial.
Processing and output:
You will process each pair of lines, representing two polynomials and will:
1. Output them first as they appear in the file and then in canonical form.
Then compute and output, all in canonical form:
2. Their sum (add them)
3. Their difference (subtract them)
4. Their product (multiply them).
Output them to a file in your program’s directory called output.txt

<h3>Online Demo: </h3> http://goo.gl/fEMXNR
<p>Note: First click on <em><b>Compile</b></em> then <em><b>Execute</b></em>. If there are issues with compiling or running, please click this link again and make sure all files are listed on the left side.</p>
