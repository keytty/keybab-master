type t =
  | J
  | Digit(int)
  | UDKey(string);

let keyToKeybol = key =>
  switch (key) {
  | "j" => J
  | k => UDKey(k)
  };

let validKeybab = cs => {
  let filterOutUndefined = c =>
    switch (c) {
    | J => true
    | UDKey(_) => false
    };

  cs |> List.filter(filterOutUndefined);
};

let digits = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9] |> List.map(n => Digit(n));
