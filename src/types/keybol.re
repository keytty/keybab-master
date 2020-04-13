type t =
  | UDKey(string)
  | J
  | Dgt(Digit.t);

let keyToKeybol = key =>
  switch (key) {
  | "0" => Dgt(D0)
  | "1" => Dgt(D1)
  | "2" => Dgt(D2)
  | "3" => Dgt(D3)
  | "4" => Dgt(D4)
  | "5" => Dgt(D5)
  | "6" => Dgt(D6)
  | "7" => Dgt(D7)
  | "8" => Dgt(D8)
  | "9" => Dgt(D9)
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

let allDigitKeybols =
  Digit.[D0, D1, D2, D3, D4, D5, D6, D7, D8, D9] |> List.map(n => Dgt(n));
