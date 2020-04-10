module Command = {
  [@bs.deriving accessors]
  type command =
    | J
    | UDKey(string);

  let keyToCommand = key =>
    switch (key) {
    | "j" => J
    | x => UDKey(x)
    };

  let filterUndefined = c =>
    switch (c) {
    | J => true
    | UDKey(_) => false
    };
};

open Command;

module Feedback = {
  type feedback =
    | NoFeedback
    | MsgFeedback(string);

  let feedbackForLastCommand = c =>
    switch (c) {
    | UDKey(k) => MsgFeedback(k ++ " is undefined")
    | _ => NoFeedback
    };
};

open Feedback;

module Action = {
  [@bs.deriving accessors]
  type actionType =
    | Move
    | NoAction;

  type action = {
    [@bs.as "type"]
    type_: actionType,
  };
};

open Action;

type instruction = {
  actions: list(action),
  commands: list(command),
  feedback,
  nextAvailables: list(command),
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

let instructionFromCommands = cs => {
  actions: cs |> actions,
  commands: cs |> List.filter(filterUndefined),
  feedback: cs |> List.rev |> List.hd |> feedbackForLastCommand,
  nextAvailables: [J],
};

let instruction = ks =>
  ks |> List.map(keyToCommand) |> instructionFromCommands;
