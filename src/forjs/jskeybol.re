type t = string;

module Glossary = {
  let j = "j";
  let d0 = "0";
  let d1 = "1";
  let d2 = "2";
  let d3 = "3";
  let d4 = "4";
  let d5 = "5";
  let d6 = "6";
  let d7 = "7";
  let d8 = "8";
  let d9 = "9";
  let digits = [|d0, d1, d2, d3, d4, d5, d6, d7, d8, d9|];
};

open Digit;
open Glossary;

let digitToJs = d =>
  switch (d) {
  | D0 => d0
  | D1 => d1
  | D2 => d2
  | D3 => d3
  | D4 => d4
  | D5 => d5
  | D6 => d6
  | D7 => d7
  | D8 => d8
  | D9 => d9
  };

open Keybol;

let keybolToJs = (c: Keybol.t) =>
  switch (c) {
  | J => Glossary.j
  | Dgt(n) => digitToJs(n)
  | UDKey(k) => k
  };
