open Keybol;

let validKeybab = kbab => {
  let filterOutUndefined = c =>
    switch (c) {
    | UDKey(_) => false
    | _ => true
    };

  kbab |> List.filter(filterOutUndefined);
};

//TODO: implement
let tidy_folder = (left: Mariekondo.t, _right: Keybol.t): Mariekondo.t => left;

let tidy = kbab =>
  kbab
  |> validKeybab
  |> List.fold_left(tidy_folder, Mariekondo.zen)
  |> Mariekondo.evaluate;
