open Keybol;

module Internal = {
  let filterNonDigits = kb =>
    switch (kb) {
    | Dgt(_) => true
    | _ => false
    };

  let dgtToDigit = dgt =>
    switch (dgt) {
    | Dgt(d) => d
    | _ => Digit.D0
    };
};
open Internal;

let numerizeKeybab = ds =>
  ds
  |> List.filter(filterNonDigits)
  |> List.map(dgtToDigit)
  |> Digit.numerize;


//TODO: refactor for better perfomance
let numbersToKeybab = n =>
n |> string_of_int |> Js.String.split("") |> Array.to_list|> List.map(keyToKeybol);
