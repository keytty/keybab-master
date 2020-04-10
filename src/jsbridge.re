open Keybab;
open Keybab.Action;
open Keybab.Command;
open Keybab.Feedback;

type jsInstruction = {
  actions: array(action),
  commands: array(command),
  feedback: string,
  nextAvailables: array(command),
};

module Utils = {
  let feedbackToString = f =>
    switch (f) {
    | MsgFeedback(m) => m
    | NoFeedback => ""
    };

  let toArray = (ins: instruction): jsInstruction => {
    actions: ins.actions |> Array.of_list,
    commands: ins.commands |> Array.of_list,
    feedback: ins.feedback |> feedbackToString,
    nextAvailables: ins.nextAvailables |> Array.of_list,
  };
  let instructionToJS = ks => ks |> instruction |> toArray;
};

let instruction = ksArr => ksArr |> Array.to_list |> Utils.instructionToJS;

module Action = {
  include Action;
};

module Command = {
  include Command;
};
