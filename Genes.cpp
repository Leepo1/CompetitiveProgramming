#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <utility>
#include <cstring>
#define INF 2000000000
using namespace std;
#define pii pair<int, pair<int,int>>
#define pi pair<int,int>

map<char,char> nbase;

map<string,string> CodontoAminoAcid;

int currentspot=0;

string newtoupper(string s){
  string news= "";
  for(int i=0; i<s.size(); i++){
    string u;
    u.assign(1,toupper(s[i]));
    news= news+u;
  }
  return news;
}

string Transcription(string DNA){
  DNA= newtoupper(DNA);
  string RNA= "";
  for(int i=0; i<DNA.size(); i++){
    RNA= RNA + nbase[DNA[i]];
  }

  return RNA;
}

string Translation(string RNA){
  string Polypeptides= "";
  while (currentspot<RNA.size()-2 && (RNA.substr(currentspot,3)!="UAA" || RNA.substr(currentspot,3)!="UAG" || RNA.substr(currentspot,3)!="UGA")){
   Polypeptides= Polypeptides +  " "+ CodontoAminoAcid[RNA.substr(currentspot,3)];
    currentspot=currentspot+3;
  }
  return Polypeptides;
}

int main(){
  nbase['A']='U';
  nbase['T']='A';
  nbase['G']='C';
  nbase['C']='G';
  CodontoAminoAcid["UUU"]="Phenylaline(Phe)";
  CodontoAminoAcid["UUC"]="Phenylaline(Phe)";
  CodontoAminoAcid["UUA"]="Leucine(Leu)";
  CodontoAminoAcid["UUG"]="Leucine(Leu)";
  CodontoAminoAcid["UCU"]="Serine(Ser)";
  CodontoAminoAcid["UCC"]="Serine(Ser)";
  CodontoAminoAcid["UCA"]="Serine(Ser)";
  CodontoAminoAcid["UCG"]="Serine(Ser)";
  CodontoAminoAcid["UAU"]="Tyrosine(Tyr)";
  CodontoAminoAcid["UAC"]="Tyrosine(Tyr)";
  CodontoAminoAcid["UAA"]="STOP";
  CodontoAminoAcid["UAG"]="STOP";
  CodontoAminoAcid["UGA"]="STOP";
  CodontoAminoAcid["UGU"]="Cysteine(Cys)";
  CodontoAminoAcid["UGC"]="Cysteine(Cys)";
  CodontoAminoAcid["UGG"]="Tryptophan(Trp)";
  CodontoAminoAcid["CUU"]="Leucine(Leu)";
  CodontoAminoAcid["CUC"]="Leucine(Leu)";
  CodontoAminoAcid["CUA"]="Leucine(Leu)";
  CodontoAminoAcid["CUG"]="Leucine(Leu)";
  CodontoAminoAcid["CCU"]="Proline(Pro)";
  CodontoAminoAcid["CCC"]="Proline(Pro)";
  CodontoAminoAcid["CCA"]="Proline(Pro)";
  CodontoAminoAcid["CCG"]="Proline(Pro)";
  CodontoAminoAcid["CAU"]="Histidine(His)";
  CodontoAminoAcid["CAC"]="Histidine(His)";
  CodontoAminoAcid["CAA"]="Glutamine(Gln)";
  CodontoAminoAcid["CAG"]="Glutamine(Gln)";
  CodontoAminoAcid["CGU"]="Arginine(Arg)";
  CodontoAminoAcid["CGC"]="Arginine(Arg)";
  CodontoAminoAcid["CGA"]="Arginine(Arg)";
  CodontoAminoAcid["CGG"]="Arginine(Arg)";
  CodontoAminoAcid["AUU"]="Isoleucine(Ile)";
  CodontoAminoAcid["AUC"]="Isoleucine(Ile)";
  CodontoAminoAcid["AUA"]="Isoleucine(Ile)";
  CodontoAminoAcid["AUG"]="START";
  CodontoAminoAcid["ACU"]="Threonine(Thr)";
  CodontoAminoAcid["ACC"]="Threonine(Thr)";
  CodontoAminoAcid["ACA"]="Threonine(Thr)";
  CodontoAminoAcid["ACG"]="Threonine(Thr)";
  CodontoAminoAcid["AAU"]="Asparagine(Asn)";
  CodontoAminoAcid["AAC"]="Asparagine(Asn)";
  CodontoAminoAcid["AAA"]="Lysine(Lys)";
  CodontoAminoAcid["AAG"]="Lysine(Lys)";
  CodontoAminoAcid["AGU"]="Serine(Ser)";
  CodontoAminoAcid["AGC"]="Serine(Ser)";
  CodontoAminoAcid["AGA"]="Arginine(Arg)";
  CodontoAminoAcid["AGG"]="Arginine(Arg)";
  CodontoAminoAcid["GUU"]="Valine(Val)";
  CodontoAminoAcid["GUC"]="Valine(Val)";
  CodontoAminoAcid["GUA"]="Valine(Val)";
  CodontoAminoAcid["GUG"]="Valine(Val)";
  CodontoAminoAcid["GCU"]="Alanine(Ala)";
  CodontoAminoAcid["GCC"]="Alanine(Ala)";
  CodontoAminoAcid["GCA"]="Alanine(Ala)";
  CodontoAminoAcid["GCG"]="Alanine(Ala)";
  CodontoAminoAcid["GAU"]="Aspartic Acid(Asp)";
  CodontoAminoAcid["GAC"]="Aspartic Acid(Asp)";
  CodontoAminoAcid["GAA"]="Glutamic Acid(Glu)";
  CodontoAminoAcid["GAG"]="Glutamic Acid(Glu)";
  CodontoAminoAcid["GGU"]="Glycine(Gly)";
  CodontoAminoAcid["GGC"]="Glycine(Gly)";
  CodontoAminoAcid["GGA"]="Glycine(Gly)";
  CodontoAminoAcid["GGG"]="Glycine(Gly)";
  ifstream cin("Gene.in");
  ofstream cout("Gene.out");
  string given;
  cin>> given;
  cout<< Transcription(given) << endl;
  cout<< Translation(Transcription(given));


return 0;
}
