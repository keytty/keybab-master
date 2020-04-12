open Keybab;
open Feedback;
open Jsaction;
open Jscommand;

type jsInstruction = {
  actions: array(Jsaction.t),
  commands: array(Jscommand.t),
  feedback: string,
  nextAvailables: array(Jscommand.t),
};

let instructionToJs = {
  let feedbackToString = f =>
    switch (f) {
    | MsgFeedback(m) => m
    | NoFeedback => ""
    };

  let toArray = (ins: Instruction.t): jsInstruction => {
    actions: ins.actions |> List.map(actionToJs) |> Array.of_list,
    commands: ins.commands |> List.map(commandToJs) |> Array.of_list,
    feedback: ins.feedback |> feedbackToString,
    nextAvailables:
      ins.nextAvailables |> List.map(commandToJs) |> Array.of_list,
  };

  ks => ks |> Instruction.instruction |> toArray;
};

let instruction = ksArr => ksArr |> Array.to_list |> instructionToJs;

module Action = {
  include Jsaction.Glossary;
};

module Command = {
  include Jscommand.Glossary;
};
