type coordinates = {
  vertical: int,
  horizontal: int,
};

type t =
  | Move(coordinates)
  | NoAction;

let validActions = cs => {
  open Keybol;
  let keybolToAction = c =>
    switch (c) {
    | H => Move({vertical: 0, horizontal: (-1)})
    | J => Move({vertical: (-1), horizontal: 0})
    | K => Move({vertical: 1, horizontal: 0})
    | L => Move({vertical: 0, horizontal: (-1)})
    | Dgt(_) => NoAction
    | UDKey(_) => NoAction
    };

  let filterOutNoAction = a =>
    switch (a) {
    | NoAction => false
    | _ => true
    };

  cs |> List.map(keybolToAction) |> List.filter(filterOutNoAction);
};
