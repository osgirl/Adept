#
# Autogenerated by Thrift Compiler (0.9.0)
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#
require 5.6.0;
use strict;
use warnings;
use Thrift;

use thrift::adept::common::Types;

# HELPER FUNCTIONS AND STRUCTURES

package thrift::adept::common::TripleService_getEntity_args;
use base qw(Class::Accessor);

sub new {
                                                    my $classname = shift;
                                                    my $self      = {};
                                                    my $vals      = shift || {};
                                                    return bless ($self, $classname);
}

sub getName {
                                                    return 'TripleService_getEntity_args';
                                                  }

sub read {
                                                    my ($self, $input) = @_;
                                                    my $xfer  = 0;
                                                    my $fname;
                                                    my $ftype = 0;
                                                    my $fid   = 0;
                                                    $xfer += $input->readStructBegin(\$fname);
                                                    while (1) 
                                                    {
                                                      $xfer += $input->readFieldBegin(\$fname, \$ftype, \$fid);
                                                      if ($ftype == TType::STOP) {
                                                        last;
                                                      }
                                                      SWITCH: for($fid)
                                                      {
                                                          $xfer += $input->skip($ftype);
                                                      }
                                                      $xfer += $input->readFieldEnd();
                                                    }
                                                    $xfer += $input->readStructEnd();
                                                    return $xfer;
                                                  }

sub write {
                                                    my ($self, $output) = @_;
                                                    my $xfer   = 0;
                                                    $xfer += $output->writeStructBegin('TripleService_getEntity_args');
                                                    $xfer += $output->writeFieldStop();
                                                    $xfer += $output->writeStructEnd();
                                                    return $xfer;
                                                  }

package thrift::adept::common::TripleService_getEntity_result;
use base qw(Class::Accessor);
thrift::adept::common::TripleService_getEntity_result->mk_accessors( qw( success ) );

sub new {
                                                    my $classname = shift;
                                                    my $self      = {};
                                                    my $vals      = shift || {};
                                                    $self->{success} = undef;
                                                    if (UNIVERSAL::isa($vals,'HASH')) {
                                                      if (defined $vals->{success}) {
                                                        $self->{success} = $vals->{success};
                                                      }
                                                    }
                                                    return bless ($self, $classname);
}

sub getName {
                                                    return 'TripleService_getEntity_result';
                                                  }

sub read {
                                                    my ($self, $input) = @_;
                                                    my $xfer  = 0;
                                                    my $fname;
                                                    my $ftype = 0;
                                                    my $fid   = 0;
                                                    $xfer += $input->readStructBegin(\$fname);
                                                    while (1) 
                                                    {
                                                      $xfer += $input->readFieldBegin(\$fname, \$ftype, \$fid);
                                                      if ($ftype == TType::STOP) {
                                                        last;
                                                      }
                                                      SWITCH: for($fid)
                                                      {
                                                        /^0$/ && do{                                                        if ($ftype == TType::STRUCT) {
                                                          $self->{success} = new thrift::adept::common::Entity();
                                                          $xfer += $self->{success}->read($input);
                                                        } else {
                                                          $xfer += $input->skip($ftype);
                                                        }
                                                        last; };
                                                          $xfer += $input->skip($ftype);
                                                      }
                                                      $xfer += $input->readFieldEnd();
                                                    }
                                                    $xfer += $input->readStructEnd();
                                                    return $xfer;
                                                  }

sub write {
                                                    my ($self, $output) = @_;
                                                    my $xfer   = 0;
                                                    $xfer += $output->writeStructBegin('TripleService_getEntity_result');
                                                    if (defined $self->{success}) {
                                                      $xfer += $output->writeFieldBegin('success', TType::STRUCT, 0);
                                                      $xfer += $self->{success}->write($output);
                                                      $xfer += $output->writeFieldEnd();
                                                    }
                                                    $xfer += $output->writeFieldStop();
                                                    $xfer += $output->writeStructEnd();
                                                    return $xfer;
                                                  }

package thrift::adept::common::TripleService_getSlot_args;
use base qw(Class::Accessor);

sub new {
                                                    my $classname = shift;
                                                    my $self      = {};
                                                    my $vals      = shift || {};
                                                    return bless ($self, $classname);
}

sub getName {
                                                    return 'TripleService_getSlot_args';
                                                  }

sub read {
                                                    my ($self, $input) = @_;
                                                    my $xfer  = 0;
                                                    my $fname;
                                                    my $ftype = 0;
                                                    my $fid   = 0;
                                                    $xfer += $input->readStructBegin(\$fname);
                                                    while (1) 
                                                    {
                                                      $xfer += $input->readFieldBegin(\$fname, \$ftype, \$fid);
                                                      if ($ftype == TType::STOP) {
                                                        last;
                                                      }
                                                      SWITCH: for($fid)
                                                      {
                                                          $xfer += $input->skip($ftype);
                                                      }
                                                      $xfer += $input->readFieldEnd();
                                                    }
                                                    $xfer += $input->readStructEnd();
                                                    return $xfer;
                                                  }

sub write {
                                                    my ($self, $output) = @_;
                                                    my $xfer   = 0;
                                                    $xfer += $output->writeStructBegin('TripleService_getSlot_args');
                                                    $xfer += $output->writeFieldStop();
                                                    $xfer += $output->writeStructEnd();
                                                    return $xfer;
                                                  }

package thrift::adept::common::TripleService_getSlot_result;
use base qw(Class::Accessor);
thrift::adept::common::TripleService_getSlot_result->mk_accessors( qw( success ) );

sub new {
                                                    my $classname = shift;
                                                    my $self      = {};
                                                    my $vals      = shift || {};
                                                    $self->{success} = undef;
                                                    if (UNIVERSAL::isa($vals,'HASH')) {
                                                      if (defined $vals->{success}) {
                                                        $self->{success} = $vals->{success};
                                                      }
                                                    }
                                                    return bless ($self, $classname);
}

sub getName {
                                                    return 'TripleService_getSlot_result';
                                                  }

sub read {
                                                    my ($self, $input) = @_;
                                                    my $xfer  = 0;
                                                    my $fname;
                                                    my $ftype = 0;
                                                    my $fid   = 0;
                                                    $xfer += $input->readStructBegin(\$fname);
                                                    while (1) 
                                                    {
                                                      $xfer += $input->readFieldBegin(\$fname, \$ftype, \$fid);
                                                      if ($ftype == TType::STOP) {
                                                        last;
                                                      }
                                                      SWITCH: for($fid)
                                                      {
                                                        /^0$/ && do{                                                        if ($ftype == TType::STRUCT) {
                                                          $self->{success} = new thrift::adept::common::Slot();
                                                          $xfer += $self->{success}->read($input);
                                                        } else {
                                                          $xfer += $input->skip($ftype);
                                                        }
                                                        last; };
                                                          $xfer += $input->skip($ftype);
                                                      }
                                                      $xfer += $input->readFieldEnd();
                                                    }
                                                    $xfer += $input->readStructEnd();
                                                    return $xfer;
                                                  }

sub write {
                                                    my ($self, $output) = @_;
                                                    my $xfer   = 0;
                                                    $xfer += $output->writeStructBegin('TripleService_getSlot_result');
                                                    if (defined $self->{success}) {
                                                      $xfer += $output->writeFieldBegin('success', TType::STRUCT, 0);
                                                      $xfer += $self->{success}->write($output);
                                                      $xfer += $output->writeFieldEnd();
                                                    }
                                                    $xfer += $output->writeFieldStop();
                                                    $xfer += $output->writeStructEnd();
                                                    return $xfer;
                                                  }

package thrift::adept::common::TripleService_getValue_args;
use base qw(Class::Accessor);

sub new {
                                                    my $classname = shift;
                                                    my $self      = {};
                                                    my $vals      = shift || {};
                                                    return bless ($self, $classname);
}

sub getName {
                                                    return 'TripleService_getValue_args';
                                                  }

sub read {
                                                    my ($self, $input) = @_;
                                                    my $xfer  = 0;
                                                    my $fname;
                                                    my $ftype = 0;
                                                    my $fid   = 0;
                                                    $xfer += $input->readStructBegin(\$fname);
                                                    while (1) 
                                                    {
                                                      $xfer += $input->readFieldBegin(\$fname, \$ftype, \$fid);
                                                      if ($ftype == TType::STOP) {
                                                        last;
                                                      }
                                                      SWITCH: for($fid)
                                                      {
                                                          $xfer += $input->skip($ftype);
                                                      }
                                                      $xfer += $input->readFieldEnd();
                                                    }
                                                    $xfer += $input->readStructEnd();
                                                    return $xfer;
                                                  }

sub write {
                                                    my ($self, $output) = @_;
                                                    my $xfer   = 0;
                                                    $xfer += $output->writeStructBegin('TripleService_getValue_args');
                                                    $xfer += $output->writeFieldStop();
                                                    $xfer += $output->writeStructEnd();
                                                    return $xfer;
                                                  }

package thrift::adept::common::TripleService_getValue_result;
use base qw(Class::Accessor);
thrift::adept::common::TripleService_getValue_result->mk_accessors( qw( success ) );

sub new {
                                                    my $classname = shift;
                                                    my $self      = {};
                                                    my $vals      = shift || {};
                                                    $self->{success} = undef;
                                                    if (UNIVERSAL::isa($vals,'HASH')) {
                                                      if (defined $vals->{success}) {
                                                        $self->{success} = $vals->{success};
                                                      }
                                                    }
                                                    return bless ($self, $classname);
}

sub getName {
                                                    return 'TripleService_getValue_result';
                                                  }

sub read {
                                                    my ($self, $input) = @_;
                                                    my $xfer  = 0;
                                                    my $fname;
                                                    my $ftype = 0;
                                                    my $fid   = 0;
                                                    $xfer += $input->readStructBegin(\$fname);
                                                    while (1) 
                                                    {
                                                      $xfer += $input->readFieldBegin(\$fname, \$ftype, \$fid);
                                                      if ($ftype == TType::STOP) {
                                                        last;
                                                      }
                                                      SWITCH: for($fid)
                                                      {
                                                        /^0$/ && do{                                                        if ($ftype == TType::STRING) {
                                                          $xfer += $input->readString(\$self->{success});
                                                        } else {
                                                          $xfer += $input->skip($ftype);
                                                        }
                                                        last; };
                                                          $xfer += $input->skip($ftype);
                                                      }
                                                      $xfer += $input->readFieldEnd();
                                                    }
                                                    $xfer += $input->readStructEnd();
                                                    return $xfer;
                                                  }

sub write {
                                                    my ($self, $output) = @_;
                                                    my $xfer   = 0;
                                                    $xfer += $output->writeStructBegin('TripleService_getValue_result');
                                                    if (defined $self->{success}) {
                                                      $xfer += $output->writeFieldBegin('success', TType::STRING, 0);
                                                      $xfer += $output->writeString($self->{success});
                                                      $xfer += $output->writeFieldEnd();
                                                    }
                                                    $xfer += $output->writeFieldStop();
                                                    $xfer += $output->writeStructEnd();
                                                    return $xfer;
                                                  }

package thrift::adept::common::TripleServiceIf;

use strict;


sub getEntity{
  my $self = shift;

  die 'implement interface';
}

sub getSlot{
  my $self = shift;

  die 'implement interface';
}

sub getValue{
  my $self = shift;

  die 'implement interface';
}

package thrift::adept::common::TripleServiceRest;

use strict;


sub new {
                                                    my ($classname, $impl) = @_;
                                                    my $self     ={ impl => $impl };

                                                    return bless($self,$classname);
}

sub getEntity{
                                                    my ($self, $request) = @_;

                                                    return $self->{impl}->getEntity();
                                                  }

sub getSlot{
                                                    my ($self, $request) = @_;

                                                    return $self->{impl}->getSlot();
                                                  }

sub getValue{
                                                    my ($self, $request) = @_;

                                                    return $self->{impl}->getValue();
                                                  }

package thrift::adept::common::TripleServiceClient;


use base qw(thrift::adept::common::TripleServiceIf);
sub new {
                                                    my ($classname, $input, $output) = @_;
                                                    my $self      = {};
                                                    $self->{input}  = $input;
                                                    $self->{output} = defined $output ? $output : $input;
                                                    $self->{seqid}  = 0;
                                                    return bless($self,$classname);
}

sub getEntity{
  my $self = shift;

                                                                                                        $self->send_getEntity();
                                                    return $self->recv_getEntity();
}

sub send_getEntity{
  my $self = shift;

                                                    $self->{output}->writeMessageBegin('getEntity', TMessageType::CALL, $self->{seqid});
                                                    my $args = new thrift::adept::common::TripleService_getEntity_args();
                                                    $args->write($self->{output});
                                                    $self->{output}->writeMessageEnd();
                                                    $self->{output}->getTransport()->flush();
}

sub recv_getEntity{
  my $self = shift;

                                                    my $rseqid = 0;
                                                    my $fname;
                                                    my $mtype = 0;

                                                    $self->{input}->readMessageBegin(\$fname, \$mtype, \$rseqid);
                                                    if ($mtype == TMessageType::EXCEPTION) {
                                                      my $x = new TApplicationException();
                                                      $x->read($self->{input});
                                                      $self->{input}->readMessageEnd();
                                                      die $x;
                                                    }
                                                    my $result = new thrift::adept::common::TripleService_getEntity_result();
                                                    $result->read($self->{input});
                                                    $self->{input}->readMessageEnd();

                                                    if (defined $result->{success} ) {
                                                      return $result->{success};
                                                    }
                                                    die "getEntity failed: unknown result";
}
sub getSlot{
  my $self = shift;

                                                                                                        $self->send_getSlot();
                                                    return $self->recv_getSlot();
}

sub send_getSlot{
  my $self = shift;

                                                    $self->{output}->writeMessageBegin('getSlot', TMessageType::CALL, $self->{seqid});
                                                    my $args = new thrift::adept::common::TripleService_getSlot_args();
                                                    $args->write($self->{output});
                                                    $self->{output}->writeMessageEnd();
                                                    $self->{output}->getTransport()->flush();
}

sub recv_getSlot{
  my $self = shift;

                                                    my $rseqid = 0;
                                                    my $fname;
                                                    my $mtype = 0;

                                                    $self->{input}->readMessageBegin(\$fname, \$mtype, \$rseqid);
                                                    if ($mtype == TMessageType::EXCEPTION) {
                                                      my $x = new TApplicationException();
                                                      $x->read($self->{input});
                                                      $self->{input}->readMessageEnd();
                                                      die $x;
                                                    }
                                                    my $result = new thrift::adept::common::TripleService_getSlot_result();
                                                    $result->read($self->{input});
                                                    $self->{input}->readMessageEnd();

                                                    if (defined $result->{success} ) {
                                                      return $result->{success};
                                                    }
                                                    die "getSlot failed: unknown result";
}
sub getValue{
  my $self = shift;

                                                                                                        $self->send_getValue();
                                                    return $self->recv_getValue();
}

sub send_getValue{
  my $self = shift;

                                                    $self->{output}->writeMessageBegin('getValue', TMessageType::CALL, $self->{seqid});
                                                    my $args = new thrift::adept::common::TripleService_getValue_args();
                                                    $args->write($self->{output});
                                                    $self->{output}->writeMessageEnd();
                                                    $self->{output}->getTransport()->flush();
}

sub recv_getValue{
  my $self = shift;

                                                    my $rseqid = 0;
                                                    my $fname;
                                                    my $mtype = 0;

                                                    $self->{input}->readMessageBegin(\$fname, \$mtype, \$rseqid);
                                                    if ($mtype == TMessageType::EXCEPTION) {
                                                      my $x = new TApplicationException();
                                                      $x->read($self->{input});
                                                      $self->{input}->readMessageEnd();
                                                      die $x;
                                                    }
                                                    my $result = new thrift::adept::common::TripleService_getValue_result();
                                                    $result->read($self->{input});
                                                    $self->{input}->readMessageEnd();

                                                    if (defined $result->{success} ) {
                                                      return $result->{success};
                                                    }
                                                    die "getValue failed: unknown result";
}
package thrift::adept::common::TripleServiceProcessor;

use strict;


sub new {
                                                      my ($classname, $handler) = @_;
                                                      my $self      = {};
                                                      $self->{handler} = $handler;
                                                      return bless ($self, $classname);
}

sub process {
                                                      my ($self, $input, $output) = @_;
                                                      my $rseqid = 0;
                                                      my $fname  = undef;
                                                      my $mtype  = 0;

                                                      $input->readMessageBegin(\$fname, \$mtype, \$rseqid);
                                                      my $methodname = 'process_'.$fname;
                                                      if (!$self->can($methodname)) {
                                                        $input->skip(TType::STRUCT);
                                                        $input->readMessageEnd();
                                                        my $x = new TApplicationException('Function '.$fname.' not implemented.', TApplicationException::UNKNOWN_METHOD);
                                                        $output->writeMessageBegin($fname, TMessageType::EXCEPTION, $rseqid);
                                                        $x->write($output);
                                                        $output->writeMessageEnd();
                                                        $output->getTransport()->flush();
                                                        return;
                                                      }
                                                      $self->$methodname($rseqid, $input, $output);
                                                      return 1;
}

sub process_getEntity {
                                                      my ($self, $seqid, $input, $output) = @_;
                                                      my $args = new thrift::adept::common::TripleService_getEntity_args();
                                                      $args->read($input);
                                                      $input->readMessageEnd();
                                                      my $result = new thrift::adept::common::TripleService_getEntity_result();
                                                      $result->{success} = $self->{handler}->getEntity();
                                                      $output->writeMessageBegin('getEntity', TMessageType::REPLY, $seqid);
                                                      $result->write($output);
                                                      $output->writeMessageEnd();
                                                      $output->getTransport()->flush();
}

sub process_getSlot {
                                                      my ($self, $seqid, $input, $output) = @_;
                                                      my $args = new thrift::adept::common::TripleService_getSlot_args();
                                                      $args->read($input);
                                                      $input->readMessageEnd();
                                                      my $result = new thrift::adept::common::TripleService_getSlot_result();
                                                      $result->{success} = $self->{handler}->getSlot();
                                                      $output->writeMessageBegin('getSlot', TMessageType::REPLY, $seqid);
                                                      $result->write($output);
                                                      $output->writeMessageEnd();
                                                      $output->getTransport()->flush();
}

sub process_getValue {
                                                      my ($self, $seqid, $input, $output) = @_;
                                                      my $args = new thrift::adept::common::TripleService_getValue_args();
                                                      $args->read($input);
                                                      $input->readMessageEnd();
                                                      my $result = new thrift::adept::common::TripleService_getValue_result();
                                                      $result->{success} = $self->{handler}->getValue();
                                                      $output->writeMessageBegin('getValue', TMessageType::REPLY, $seqid);
                                                      $result->write($output);
                                                      $output->writeMessageEnd();
                                                      $output->getTransport()->flush();
}

1;