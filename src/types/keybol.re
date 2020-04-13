type digit =
  | D0
  | D1
  | D2
  | D3
  | D4
  | D5
  | D6
  | D7
  | D8
  | D9;

type t =
  | UDKey(string)
  | J
  | Digit(digit);

let keyToKeybol = key =>
  switch (key) {
  | "0" => Digit(D0)
  | "1" => Digit(D1)
  | "2" => Digit(D2)
  | "3" => Digit(D3)
  | "4" => Digit(D4)
  | "5" => Digit(D5)
  | "6" => Digit(D6)
  | "7" => Digit(D7)
  | "8" => Digit(D8)
  | "9" => Digit(D9)
  | "j" => J
  | k => UDKey(k)
  };

let validKeybab = cs => {
  let filterOutUndefined = c =>
    switch (c) {
    | UDKey(_) => false
    | _ => true
    };

  cs |> List.filter(filterOutUndefined);
};

let digits =
  [D0, D1, D2, D3, D4, D5, D6, D7, D8, D9] |> List.map(n => Digit(n));
