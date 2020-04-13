open Command;

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

let commandToJs = (c: Command.t) =>
  switch (c) {
  | J => Glossary.j
  | Digit(n) => n |> string_of_int
  | UDKey(k) => k
  };
