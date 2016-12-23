# libofd
The first open-source C++ development library for OFD.

"Electronic files storage and exchange formats - Fixed layout documents", referred to as OFD (Open Fixed-Layout Document), is China's independent research and development of fixed-layout format standard, is an important part of the national standard system of electronic documents.  

October 13, 2016, the official release of the OFDnational standard, the standard number: 33190-2016. GB/T standard query site http://www.sac.gov.cn/.

The libofd is the first open-source C++ development library for OFD. It was established in October 20, 2016, only 1 week later than the standard release time. 

## Release Notes

### v0.5

2016.12.16

- Complete OFD format file package.
- pdf2ofd can convernt PDF file into OFD file, include text only.
- use command "pdf2ofd <pdffile> [ofdfile]" to translate a PDF file into OFD file.
- Use command "make pdf2ofd" to build library(libofd) and tool(pdf2ofd)
- Use command "make check" to check files in package is meet the OFD standard.

## Objectives

### v1.0

- Read and write OFD files.
- Import text, path and image from PDF files.
- Render text, path and image in OFD files.

## Tools

### pdf2ofd

pdf2ofd is a tool translating a PDF file to a OFD file.

### ofdviewer


## Dependencies

- libcairo2-dev http://cairographics.org
- libtinyxml2-dev https://github.com/leethomason/tinyxml2  
- libzip-dev https://github.com/nih-at/libzip 
- easylogging++ https://github.com/easylogging/easyloggingpp

libsdl2-dev
libsdl2-image-dev
libsdl2-ttf-dev
libsdl2-mixer-dev
libsdl2-net-dev
libsdl2-gfx-dev

libharfbuzz-dev
libicu-dev

libfreetype6-dev

## Build

```
$ git clone https://github.com/idleuncle/libofd.git
```

```
$ make build
```

or

```
$ cd libofd
$ mkdir build && cd build && cmake .. && make
```

## Test

```
$ make pdf2ofd
```

or 

```
$ build/bin/pdf2ofd data/sample0.pdf
```
The command above will create a OFD file named sampl0.ofd in current directory, and upzip it into sample0 folder. See Makefile for detail.


## Errata

- Section 6.2 P4 图中表明每个Doc\_N只有一个PublicRes以及一个DocumentRes，而Section 7.5 P10 表6中PublicRes和DocumentRes的说明明确两者都是“资源序列，每个节点指向OFD包内的一个资源描述文档“，但它们的类型都是ST\_Loc。矛盾的情况下，libofd按结构图中的定义，只允许一个PublicRes、一个DocumentRes。页面中的PageRes也有同样的问题。

- Section 7.4 P8 表4第一行DocID备注“可选”，按附录A.1 OFD.xsd中P92定义应为“必选”。

- Section 8.3.2 P32 表26最后一行“格构高洛德渐变”应为“网格高洛德渐变”

- Section 8.2.1 P28 "当图元未定义绘制属性时，应首先按照图元定义的绘制参数进行渲染"该句重复，应删除。
