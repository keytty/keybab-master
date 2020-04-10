type axis =
  | Vertical
  | Horizontal;

type move = {
  axis,
  amount: int,
};

type t =
  | Move(move)
  | NoAction;

let validActions = cs => {
  let commandToAction = c =>
    switch (c) {
    | Command.J => Move({axis: Vertical, amount: (-1)})
    | UDKey(_) => NoAction
    };

  let filterOutNoAction = a =>
    switch (a) {
    | NoAction => false
    | _ => true
    };

  cs |> List.map(commandToAction) |> List.filter(filterOutNoAction);
};
