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

let numerizeKeybol = ds =>
  ds
  |> List.filter(filterNonDigits)
  |> List.map(dgtToDigit)
  |> Digit.numerize;
