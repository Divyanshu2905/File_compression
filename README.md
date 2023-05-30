
# The Compression Tool

The file compression tool is a software application that aims to reduce the size of files while preserving their original content. It utilizes various compression algorithms, such as Huffman coding, to achieve efficient file compression and decompression.


## Features

- **Compression**: The tool provides the ability to compress files by analyzing their content and applying suitable compression techniques. It employs Huffman coding, a popular lossless compression algorithm, to create a compact representation of the file's data.
- **Decompression**: The tool also supports decompression of compressed files. It can accurately reconstruct the original file from its compressed form using the same compression algorithm.
- **Compression Efficiency**: The tool employs various techniques to achieve optimal compression ratios. It analyzes the frequency of characters or patterns in the input file and assigns shorter codes to more frequent elements, resulting in more efficient compression.
- **User Interface**: The application features a user-friendly interface that allows users to select files for compression or decompression. It provides options to specify the input file and the destination for the compressed or decompressed file.
- **File Integrity**: The tool ensures that the compressed file retains the integrity of the original file during compression and decompression processes. It guarantees lossless compression, meaning that the decompressed file will be an exact replica of the original file.
- **Performance Optimization**: The application is designed to handle large files efficiently. It utilizes memory management techniques to minimize memory usage during compression and decompression operations, ensuring optimal performance even for files of significant size.


## Compression

The Project uses heap and custom data structures to effectively imply huffman coding (a greedy algorithm) to encode data. It uses fstream library to import data from input file and then process it and finally write the encoded data in binary form to the file destined file. It writes data in a group of 8 bits prviding a fast writing speed.
### Deployment

#### To use compression tool use:-

```bash
  ./compress.exe
```
Use this command in library containing this file

#### After this input the file name

```bash
  File to compress: input.txt
```
#### Input the destination file for compressed data
```bash
  Enter destination: compress.bin
```
#### Your file will be succesfully compressed
```bash
  processing..!
  Completed
```

## Decompression

For decompression it uses the already stored encoding map in the compressed file and using it decodes the data. For reading and writing it uses fstream. The storage of encoding map within the file allows even faster decompression and writes the decompressed data in destined file.
### Deployment

#### To use decompression tool use:-

```bash
  ./decompress.exe
```
Use this command in library containing this file

#### After this input the file name

```bash
  File to compress: compress.bin
```
#### Input the destination file for decompressed data
```bash
  Enter destination: output.txt
```
#### Your file will be succesfully decompressed
```bash
  processing..!
  Completed
```
## Authors

- [@Divyanshu2905](https://github.com/Divyanshu2905)

