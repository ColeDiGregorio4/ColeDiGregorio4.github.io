## Project Description:
The Cipher project implements a variation of a Caesar cipher with a repeating key. Instead of shifting each character by a constant amount, the key determines a unique shift for each letter in the input message. It supports encoding and decoding with custom key values.
- Encapsulation: Core functionality encapsulated in the Cipher class with methods like encodeMessage and decodeMessage.
- Error Handling: Validation for key inputs and error reporting for invalid cases.
- Modular Design: Use of helper functions (getLetterNumber, getLetter) to simplify and clarify logic.
- Dynamic Data Structures: Utilizes a queue for managing repeating key characters.
- Reusability: Default and parameterized constructors for flexible initialization.
- Algorithmic Thinking: Implements custom letter shifting logic to encode and decode messages effectively.

## Code

<div style="display: flex; gap: 20px; margin-top: 20px;">
    <a href="/Cipher/Cipher.cpp" style="text-decoration: none; color: white; background-color: #000000; padding: 5px 10px; border-radius: 5px;">Cipher.cpp</a>
    <a href="/Cipher/Cipher.h" style="text-decoration: none; color: white; background-color: #000000; padding: 5px 10px; border-radius: 5px;">Cipher.h</a>
    <a href="/Cipher/Project3.cpp" style="text-decoration: none; color: white; background-color: #000000; padding: 5px 10px; border-radius: 5px;">Driver.cpp</a>
    <a href="/Cipher/Queue.cpp" style="text-decoration: none; color: white; background-color: #000000; padding: 5px 10px; border-radius: 5px;">Queue.cpp</a>
    <a href="/Cipher/Queue.h" style="text-decoration: none; color: white; background-color: #000000; padding: 5px 10px; border-radius: 5px;">Queue.h</a>
</div>
