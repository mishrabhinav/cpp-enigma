CPP Enigma
==========

This is a simple C++ implementation of the Enigma Machine. The only difference
is that the program can run with multiple rotors.

There are sample rotor configuration files in rotors/
and plugboard configuration files in plugboards/

To build the project, run `make`. This will compile all the files and produce
an executable file `enigma`. Run the executable with provided configuration
files. The last config file should correspond to the plugboard configuration.

For example:
`./enigma rotors/I.rot rotors/II.rot plugboards/I.pb`
