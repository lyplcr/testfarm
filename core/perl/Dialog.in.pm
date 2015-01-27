##
## TestFarm
## Error/Warning dialog window
##
## $Revision: 144 $
## $Date: 2006-07-19 14:41:36 +0200 (mer., 19 juil. 2006) $
##

package TestFarm::Dialog;

use Gtk2;
use Gtk2::GladeXML;

my %dialog = ();

my $dialog_interface = << '__GLADE_INTERFACE__';
__GLADE_INTERFACE__


sub dialog_clicked {
  my $id = shift;

  if ( $dialog{$id} ) {
    &{$dialog{$id}}($dialog{arg});
  }
  $dialog{w}->destroy();
}


sub dialog_ok_clicked { dialog_clicked('ok') }
sub dialog_cancel_clicked { dialog_clicked('cancel') }
sub dialog_yes_clicked { dialog_clicked('yes') }
sub dialog_no_clicked { dialog_clicked('no') }


sub dialog_destroyed {
  $dialog{g} = undef;
  %dialog = ();
}


sub dialog_interface($) {
  my $root = shift;

  my $g = undef;
  if ( $dialog_interface =~ /^\s*$/ ) {
    my $file = 'TDialog.glade';
    print STDERR "Loading Glade interface from XML file $file\n";
    $g = Gtk2::GladeXML->new($file, $root);
  }
  else {
    $g = Gtk2::GladeXML->new_from_buffer($dialog_interface, $root);
  }

  return $g;
}


sub dialog($$;$$) {
  my $type = shift;
  my $text = shift;
  $dialog{ok} = shift;
  $dialog{arg} = shift;

  $dialog{g} = dialog_interface($type);
  $dialog{g}->signal_autoconnect_from_package('TestFarm::Dialog');

  $dialog{w} = $dialog{g}->get_widget($type);

  my $label = $dialog{g}->get_widget('label');
  $label->set_text($text);
}


sub error($;$$) {
  my ($text, $ok, $arg) = @_;
  dialog('error', $text, $ok, $arg);
}


sub warning($;$$) {
  my ($text, $ok, $arg) = @_;
  dialog('warning', $text, $ok, $arg);
}


sub question($;$$$) {
  my $text = shift;
  $dialog{yes} = shift;
  $dialog{no} = shift;
  $dialog{arg} = shift;

  $dialog{g} = dialog_interface('question');
  $dialog{g}->signal_autoconnect_from_package('TestFarm::Dialog');

  $dialog{w} = $dialog{g}->get_widget('question');

  my $label = $dialog{g}->get_widget('label');
  $label->set_text($text);
}


1;
