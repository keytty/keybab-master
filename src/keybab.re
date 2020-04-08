type command =
  | J
  | UDKey(char);

let keyToCommand = key =>
  switch (key) {
  | 'j' => J
  | x => UDKey(x)
  };

let filterUndefined = c =>
  switch (c) {
  | J => true
  | UDKey(_) => false
  };

type feedback =
  | None
  | Feedback(string);

let feedbackForLastCommand = c =>
  switch (c) {
  | UDKey(k) => Feedback(String.make(1, k) ++ " is undefined")
  | _ => None
  };

type actionType =
  | Move
  | NoAction;

type action = {
  [@bs.as "type"]
  type_: actionType,
};

type instruction = {
  actions: list(action),
  commands: list(command),
  feedback,
  nextAvailable: list(command),
};

let action = c =>
  switch (c) {
  | J => {type_: Move}
  | UDKey(_) => {type_: NoAction}
  };

let actions = cs =>
  cs
  |> List.map(action)
  |> List.filter(a =>
       switch (a) {
       | {type_: NoAction} => false
       | _ => true
       }
     );

let instruction = cs => {
  actions: cs |> actions,
  commands: cs |> List.filter(filterUndefined),
  feedback: cs |> List.rev |> List.hd |> feedbackForLastCommand,
  nextAvailable: [J],
};
