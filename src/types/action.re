type coordinates = {
  vertical: int,
  horizontal: int,
};

type t =
  | Move(coordinates)
  | NoAction;

let validActions = cs => {
  let commandToAction = c =>
    switch (c) {
    | Command.J => Move({vertical: (-1), horizontal: 0})
    | UDKey(_) => NoAction
    };

  let filterOutNoAction = a =>
    switch (a) {
    | NoAction => false
    | _ => true
    };

  cs |> List.map(commandToAction) |> List.filter(filterOutNoAction);
};
