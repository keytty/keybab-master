type t =
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

type digits = list(t);

let digitToNumber = d =>
  switch (d) {
  | D0 => 0
  | D1 => 1
  | D2 => 2
  | D3 => 3
  | D4 => 4
  | D5 => 5
  | D6 => 6
  | D7 => 7
  | D8 => 8
  | D9 => 9
  };

let numerize = ns =>
  ns |> List.map(digitToNumber) |> List.fold_left((l, r) => l * 10 + r, 0);
