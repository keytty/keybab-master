open Command;

type t = string;

module Glossary = {
  let j = "j";
};

let commandToJs =
  fun
  | J => Glossary.j
  | UDKey(k) => k;
