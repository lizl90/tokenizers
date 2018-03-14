
<!-- README.md is generated from README.Rmd. Please edit that file -->

# tokenizers

[![CRAN\_Status\_Badge](http://www.r-pkg.org/badges/version/tokenizers)](http://cran.r-project.org/package=tokenizers)
[![CRAN\_Downloads](http://cranlogs.r-pkg.org/badges/grand-total/tokenizers)](http://cran.r-project.org/package=tokenizers)
[![Travis-CI Build
Status](https://travis-ci.org/ropensci/tokenizers.svg?branch=master)](https://travis-ci.org/ropensci/tokenizers)
[![Appveyor Build
status](https://ci.appveyor.com/api/projects/status/qx3vh3ukjgo99iu4/branch/master?svg=true)](https://ci.appveyor.com/project/lmullen/tokenizers-dkf3v/branch/master)
[![Coverage
Status](https://img.shields.io/codecov/c/github/ropensci/tokenizers/master.svg)](https://codecov.io/github/ropensci/tokenizers?branch=master)
[![](https://badges.ropensci.org/33_status.svg)](https://github.com/ropensci/onboarding/issues/33)

## Overview

This R package offers functions with a consistent interface to convert
natural language text into tokens. Includes tokenizers for shingled
n-grams, skip n-grams, words, word stems, sentences, paragraphs,
characters, shingled characters, lines, tweets, Penn Treebank, and
regular expressions, as well as functions for counting characters,
words, and sentences, and a function for splitting longer texts into
separate documents, each with the same number of words. The package is
built on the [stringi](http://www.gagolewski.com/software/stringi/) and
[Rcpp](http://www.rcpp.org/) packages for lightening fast yet correct
tokenization in UTF-8.

See the “[Introduction to the tokenizers
Package](https://ropensci.github.io/tokenizers/articles/introduction-to-tokenizers.html)”
vignette for an overview of all the functions in this package.

This package complies with the standards for input and output
recommended by the Text Interchange Formats. The TIF initiative was
created at an rOpenSci meeting in 2017, and its recommendations are
available as part of the [tif package](https://github.com/ropensci/tif).
See the “[The Text Interchange Formats and the tokenizers
Package](https://ropensci.github.io/tokenizers/articles/tif-and-tokenizers.html)”
vignette for an explanation of how this package fits into that
ecosystem.

## Installation

You can install this package from CRAN:

``` r
install.packages("tokenizers")
```

To get the development version from GitHub, use
[devtools](https://github.com/hadley/devtools).

``` r
# install.packages("devtools")
devtools::install_github("ropensci/tokenizers")
```

## Examples

The tokenizers in this package have a consistent interface. They all
take either a character vector of any length, or a list where each
element is a character vector of length one. The idea is that each
element comprises a text. Then each function returns a list with the
same length as the input vector, where each element in the list contains
the tokens generated by the function. If the input character vector or
list is named, then the names are preserved, so that the names can serve
as identifiers.

``` r
library(magrittr)
library(tokenizers)

james <- paste0(
  "The question thus becomes a verbal one\n",
  "again; and our knowledge of all these early stages of thought and feeling\n",
  "is in any case so conjectural and imperfect that farther discussion would\n",
  "not be worth while.\n",
  "\n",
  "Religion, therefore, as I now ask you arbitrarily to take it, shall mean\n",
  "for us _the feelings, acts, and experiences of individual men in their\n",
  "solitude, so far as they apprehend themselves to stand in relation to\n",
  "whatever they may consider the divine_. Since the relation may be either\n",
  "moral, physical, or ritual, it is evident that out of religion in the\n",
  "sense in which we take it, theologies, philosophies, and ecclesiastical\n",
  "organizations may secondarily grow.\n"
)
names(james) <- "varieties"

tokenize_characters(james)[[1]] %>% head(50)
#>  [1] "t" "h" "e" "q" "u" "e" "s" "t" "i" "o" "n" "t" "h" "u" "s" "b" "e"
#> [18] "c" "o" "m" "e" "s" "a" "v" "e" "r" "b" "a" "l" "o" "n" "e" "a" "g"
#> [35] "a" "i" "n" "a" "n" "d" "o" "u" "r" "k" "n" "o" "w" "l" "e" "d"
tokenize_character_shingles(james)[[1]] %>% head(20)
#>  [1] "the" "heq" "equ" "que" "ues" "est" "sti" "tio" "ion" "ont" "nth"
#> [12] "thu" "hus" "usb" "sbe" "bec" "eco" "com" "ome" "mes"
tokenize_words(james)[[1]] %>% head(10)
#>  [1] "the"      "question" "thus"     "becomes"  "a"        "verbal"  
#>  [7] "one"      "again"    "and"      "our"
tokenize_word_stems(james)[[1]] %>% head(10)
#>  [1] "the"      "question" "thus"     "becom"    "a"        "verbal"  
#>  [7] "one"      "again"    "and"      "our"
tokenize_sentences(james) 
#> $varieties
#> [1] "The question thus becomes a verbal one again; and our knowledge of all these early stages of thought and feeling is in any case so conjectural and imperfect that farther discussion would not be worth while."                                               
#> [2] "Religion, therefore, as I now ask you arbitrarily to take it, shall mean for us _the feelings, acts, and experiences of individual men in their solitude, so far as they apprehend themselves to stand in relation to whatever they may consider the divine_."
#> [3] "Since the relation may be either moral, physical, or ritual, it is evident that out of religion in the sense in which we take it, theologies, philosophies, and ecclesiastical organizations may secondarily grow."
tokenize_paragraphs(james)
#> $varieties
#> [1] "The question thus becomes a verbal one again; and our knowledge of all these early stages of thought and feeling is in any case so conjectural and imperfect that farther discussion would not be worth while."                                                                                                                                                                                                                                                                   
#> [2] "Religion, therefore, as I now ask you arbitrarily to take it, shall mean for us _the feelings, acts, and experiences of individual men in their solitude, so far as they apprehend themselves to stand in relation to whatever they may consider the divine_. Since the relation may be either moral, physical, or ritual, it is evident that out of religion in the sense in which we take it, theologies, philosophies, and ecclesiastical organizations may secondarily grow. "
tokenize_ngrams(james, n = 5, n_min = 2)[[1]] %>% head(10)
#>  [1] "the question"                   "the question thus"             
#>  [3] "the question thus becomes"      "the question thus becomes a"   
#>  [5] "question thus"                  "question thus becomes"         
#>  [7] "question thus becomes a"        "question thus becomes a verbal"
#>  [9] "thus becomes"                   "thus becomes a"
tokenize_skip_ngrams(james, n = 5, k = 2)[[1]] %>% head(10)
#>  [1] "the"                  "the question"         "the thus"            
#>  [4] "the becomes"          "the question thus"    "the question becomes"
#>  [7] "the question a"       "the thus becomes"     "the thus a"          
#> [10] "the thus verbal"
tokenize_ptb(james)[[1]] %>% head(10)
#>  [1] "The"      "question" "thus"     "becomes"  "a"        "verbal"  
#>  [7] "one"      "again"    ";"        "and"
tokenize_lines(james)[[1]] %>% head(5)
#> [1] "The question thus becomes a verbal one"                                   
#> [2] "again; and our knowledge of all these early stages of thought and feeling"
#> [3] "is in any case so conjectural and imperfect that farther discussion would"
#> [4] "not be worth while."                                                      
#> [5] "Religion, therefore, as I now ask you arbitrarily to take it, shall mean"
tokenize_tweets("Hey @handle, #rstats is awesome!")[[1]]
#> [1] "hey"     "@handle" "#rstats" "is"      "awesome"
```

The package also contains functions to count words, characters, and
sentences, and these functions follow the same consistent interface.

``` r
count_words(james)
#> varieties 
#>       112
count_characters(james)
#> varieties 
#>       673
count_sentences(james)
#> varieties 
#>        13
```

The `chunk_text()` function splits a document into smaller chunks, each
with the same number of words.

## Contributing

Contributions to the package are more than welcome. One way that you can
help is by using this package in your R package for natural language
processing. If you want to contribute a tokenization function to this
package, it should follow the same conventions as the rest of the
functions whenever it makes sense to do so.

Please note that this project is released with a [Contributor Code of
Conduct](CONDUCT.md). By participating in this project you agree to
abide by its terms.

-----

[![rOpenSCi
logo](http://ropensci.org/public_images/github_footer.png)](http://ropensci.org)
