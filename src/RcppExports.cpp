// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// generate_ngrams_batch
ListOf<CharacterVector> generate_ngrams_batch(const ListOf<const CharacterVector> documents_list, const int ngram_min, const int ngram_max, CharacterVector stopwords, const String ngram_delim);
RcppExport SEXP tokenizers_generate_ngrams_batch(SEXP documents_listSEXP, SEXP ngram_minSEXP, SEXP ngram_maxSEXP, SEXP stopwordsSEXP, SEXP ngram_delimSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const ListOf<const CharacterVector> >::type documents_list(documents_listSEXP);
    Rcpp::traits::input_parameter< const int >::type ngram_min(ngram_minSEXP);
    Rcpp::traits::input_parameter< const int >::type ngram_max(ngram_maxSEXP);
    Rcpp::traits::input_parameter< CharacterVector >::type stopwords(stopwordsSEXP);
    Rcpp::traits::input_parameter< const String >::type ngram_delim(ngram_delimSEXP);
    rcpp_result_gen = Rcpp::wrap(generate_ngrams_batch(documents_list, ngram_min, ngram_max, stopwords, ngram_delim));
    return rcpp_result_gen;
END_RCPP
}
// skip_ngrams
CharacterVector skip_ngrams(CharacterVector words, int n, int k);
RcppExport SEXP tokenizers_skip_ngrams(SEXP wordsSEXP, SEXP nSEXP, SEXP kSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< CharacterVector >::type words(wordsSEXP);
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    Rcpp::traits::input_parameter< int >::type k(kSEXP);
    rcpp_result_gen = Rcpp::wrap(skip_ngrams(words, n, k));
    return rcpp_result_gen;
END_RCPP
}
