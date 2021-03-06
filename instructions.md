# Programming Task

For a data processing task, we have an input file where each byte represents a
symbol in an input sequence. We wish to store this sequence in RAM and be able
to **access a symbol at a given index in constant time**. However, the large
length of the sequence is problematic due to memory constraints. The symbols in
the sequence generally occur in a non-repeating order, and the probability
distribution of the symbols is close to uniform. In practice, the number of
unique symbols in the sequence is small (often ≤ 16) but may take arbitrary
values. For example, when rendered using ASCII, an input file might contain:

```
RYKARRKAAGCWATYWKMTCTWRAGSRMGCTKGTKCACMYACYTTMG
```

You have been given a zip file containing a basic solution to this task. It
contains:

1. The source code for an application that reads input data from stdin and
   writes a compact representation of the file to stdout.
2. The source code for an application that reads the compact representation
   from stdin and writes the reconstructed original data to stdout.
3. A build system to build these applications.
4. The above example data set in a file called `example.dat`.
4. A script to test the solution with an example data set `test.sh example.dat`.

Your task is to improve the given solution to a production quality software
project. We will evaluate the exercise on the following criteria:

* Code clarity and correctness.
* Error detection and handling / reporting (this need not be more complex than
  printing a comprehensible error message then exiting, but it should not be
  easily possible to crash your code).
* Appropriate use of commenting.
* Documentation on how to build and run your solution.
* Use of appropriate build tools.
* Edge case handling.
* Presence of automatable testing.

It is important that you do not change the interface to the applications as we
will use this to test your solution.

Please include a README file explaining how to use your project, your design
choices and any features and / or limitations of your implementation that you
feel are important.

Performance optimisation is not a primary focus of this exercise and should not
be undertaken in a way that compromises the other listed criteria. However,
implementations that have pathological performance issues are undesirable. You
may assume that the machine on which your application executes has sufficient
memory to hold the entire input sequence (it is the later computation on input
sequence that necessitates its efficient storage in memory due to the presence
of other memory-hungry data structures).

Please submit your implementation as a tarball or zip file.
