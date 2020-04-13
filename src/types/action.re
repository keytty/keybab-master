type coordinates = {
  vertical: int,
  horizontal: int,
};

type t =
  | Move(coordinates)
  | NoAction;

let validActions = cs => {
  let keybolToAction = c =>
    switch (c) {
    | Keybol.J => Move({vertical: (-1), horizontal: 0})
    | Digit(_) => NoAction
    | UDKey(_) => NoAction
    };

  let filterOutNoAction = a =>
    switch (a) {
    | NoAction => false
    | _ => true
    };

  cs |> List.map(keybolToAction) |> List.filter(filterOutNoAction);
};
